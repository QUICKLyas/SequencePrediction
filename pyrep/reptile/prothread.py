import threading
from concurrent.futures import thread
from queue import Queue
from threading import Thread, Condition
from pyrep.reptile.webrep import WebRep
from pyrep.reptile.db import DB
from pyrep.config.config import pages,start_page,end_page
from pyrep.util.file import read_json_file, delete_json_file_data
import time

condition = Condition()

file_count:int = 1 # 文件可以存放一个list数据


class WebRepThread(Thread):
    def __init__(self, thread_id: int, name, page=0, con: Condition = None):
        Thread.__init__(self)  # 自定义为一个线程
        self.thread_id = thread_id
        self.name = name
        self.count = page
        self.web_rep = WebRep()
        self.condition = con

    def run(self):
        # 读取文件从网站中
        self.condition.acquire()
        global file_count
        while True:
            print_message(self.thread_id, self.name, "get Permission, page: {}".format(self.count))
            json_data = self.web_rep.get_html_text(page=self.count)
            list_data = self.web_rep.parse_text(self.web_rep, list_data=json_data)
            # 保存数据到文件中
            print_message(self.thread_id, self.name, "length: {}".format(len(list_data)))
            dict_note = self.web_rep.write_text(self.web_rep, list_data=list_data)
            file_count -= 1
            self.count += 1
            print_message(self.thread_id, self.name, dict_note.get('message') + " semaphore:{}, page:{}".format(file_count, self.count))
            # 如果文件资源已经使用完毕，说明这个时候不能生产，需要消费
            if file_count == 0:
                self.condition.notify()
                self.condition.wait()
            if self.count >= pages:
                break
        self.condition.release()
        end_thread(self)


class DBThread(Thread):
    def __init__(self, thread_id: int, name: str, con: Condition = None):
        Thread.__init__(self)
        self.thread_id = thread_id
        self.name = name
        self.db = DB()
        self.condition = con

    def run(self):
        global file_count
        self.condition.acquire()
        while True:
            print_message(self.thread_id, self.name, "get Permission for reading file")
            dict_note = self.db.insert_list_data()
            print_message(self.thread_id, self.name, "length: {}".format(len(dict_note.get('data'))))

            file_count += 1
            print_message(self.thread_id, self.name, dict_note.get('message') + " semaphore: {}".format(file_count))

            # 说明此时文件操作权限为1，需要生产者
            if file_count == 1:
                self.condition.notify()
                length = len(dict_note.get('data'))
                if length != 30:
                    break
                self.condition.wait()
        self.condition.release()
        end_thread(self)


def print_message(thread_id: int, name, message: str) -> None:
    print("Thread:" + name + "-" + str(thread_id) + "@" + time.ctime(time.time()) + ":" + message)


def start_thread(th: Thread) -> None:
    print("Starting thread: {}".format(th.name))
    th.start()  # 内部启动


def end_thread(th: Thread) -> None:
    print("Ending thread: {}".format(th.name))



def threads_start():
    thread_web_reptile = WebRepThread(1, "WebRepThread", start_page, condition)
    thread_db = DBThread(3, "DBThread", condition)

    start_thread(thread_web_reptile)
    start_thread(thread_db)

    thread_web_reptile.join()
    thread_db.join()

