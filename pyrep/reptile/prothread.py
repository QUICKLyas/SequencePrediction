import threading
from queue import Queue
from threading import Thread, Condition
from pyrep.reptile.webrep import WebRep
from pyrep.reptile.db import DB
from pyrep.util.file import read_json_file, delete_json_file_data
import time

# 设定锁
threadLock = threading.Lock()
#  线程池
thread_list = []
threads_waiting = []
threads_ready = []
# 缓存区记录，默认只有一个空间，就是每次生产完成之后就要等待消费
thread_public_file: list = [0]
condition = Condition()
queue_run = Queue(1)
# 等待唤醒的进程

queue_wait = Queue(2)
class WebRepThreadGetSpringText(Thread):
    def __init__(self, thread_id: int, name, page=0):
        Thread.__init__(self)  # 自定义为一个线程
        self.exit_flag = True
        self.thread_id = thread_id
        self.name = name
        self.count = page
        self.web_rep = WebRep()

    def run(self):
        # 读取文件从网站中
        json_data = self.web_rep.get_html_text(page=self.count)

        # while self.exit_flag:
        #     if self.count < 1:
        #         threadLock.acquire()
        #         # 读取数据
        #         json_data = self.web_rep.get_html_text(page=self.count)
        #         # 写入数据
        #         self.web_rep.write_text(self.web_rep, list_data=json_data)
        #         # 输出信息
        #         print_message(self.thread_id, self.name, self.count, str(type(json_data)))
        #         self.count += 1
        #         threadLock.release()
        #     else:
        #         self.exit_flag = False
        # end_thread(self)


class WebRepThreadParseText(Thread):
    def __init__(self, thread_id: int, name: str):
        Thread.__init__(self)
        self.exit_flag = True
        self.thread_id = thread_id
        self.name = name
        self.web_rep = WebRep()

    def run(self) -> None:
        while self.exit_flag:
            threadLock.acquire()
            text = read_json_file()
            delete_json_file_data()
            if len(text) != 0:
                json_data = self.web_rep.parse_text(self.web_rep, list_data=text.get('data'))
                self.web_rep.write_text(self.web_rep, list_data=json_data)
                threadLock.release()
            else:
                self.exit_flag = False


class DBThread(Thread):
    def __init__(self, thread_id: int, name: str):
        Thread.__init__(self)
        self.exit_flag = True
        self.thread_id = thread_id
        self.name = name
        self.db = DB()

    def run(self):
        while self.exit_flag:
            threadLock.acquire()
            self.exit_flag = self.db.insert_list_data()
            threadLock.release()


def print_message(thread_id: int, name, counter, message: str) -> None:
    print("Thread:" + name + "-" + str(thread_id) + "@" + time.ctime(time.time()) + ":" + message)


def start_thread(thread: Thread) -> None:
    thread.start()  # 内部启动
    print("Starting thread:", thread.name)


def end_thread(thread: Thread) -> None:
    print("Ending thread:", thread.name)
