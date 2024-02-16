import threading
from pyrep.config.config import pages
from threading import Thread
from pyrep.reptile.webrep import WebRep
from pyrep.reptile.db import DB
from pyrep.util.file import read_json_file, delete_json_file
import time

# 设定锁
threadLock = threading.Lock()
#  线程池
thread_list = []
threads_waiting = []
threads_ready = []


class WebRepThreadGetSpringText(Thread):
    def __init__(self, thread_id: int, name, page=0):
        Thread.__init__(self)  # 自定义为一个线程
        self.exit_flag = True
        self.thread_id = thread_id
        self.name = name
        self.count = page
        self.web_rep = WebRep()



    def run(self):
        while self.exit_flag:
            if self.count < pages:
                threadLock.acquire()
                # 读取数据
                json_data = self.web_rep.get_html_text(page=self.count)
                # 写入数据
                self.web_rep.write_text(self.web_rep, list_data=json_data)
                # 输出信息
                print_message(self.thread_id, self.name, self.count, str(type(json_data)))
                self.count += 1
                threadLock.release()
            else:
                self.exit_flag = False
        end_thread(self)


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
            delete_json_file()
            threadLock.release()
            if len(text) != 0:
                json_data = self.web_rep.parse_text(self.web_rep, list_data=text)
                threadLock.acquire()
                self.web_rep.write_text(self.web_rep,list_data=json_data)
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
            # threadLock.acquire()
            # json_data = read_json_file()
            # delete_json_file()
            # threadLock.release()
            # if len(json_data) != 0:
            #     threadLock.acquire()
            #     self.db.insert_json(self.db, json_data)


def print_message(thread_id: int, name, counter,message:str) -> None:
    print("Thread:" + name + "-" + str(thread_id) + "@" + time.ctime(time.time()) + ":" + message)

def start_thread(thread: Thread) -> None:
    thread.start()  # 内部启动
    print("Starting thread:" , thread.name)

def end_thread(thread: Thread) -> None:
    print("Ending thread:", thread.name)
def step_1(page=0) -> list:
    answer = web_rep.get_html_text(page=page)
    return answer


# 如果结果为False，说明已经没有新的数据得到，True 需要进入下一步
def step_2(list_data: list) -> bool:
    answer = web_rep.write_text(
        web_rep, web_rep.parse_text(
            web_rep, list_data=list_data))
    return answer


def step_3():
    db.insert_list_data()
    # Thread(target=WebRep.get_html_text, args=(web_rep, page))
    # th_webrep_get = Thread(target=WebRep.get_html_text, {})


th_1 = Thread(target=step_1)
th_2 = Thread(target=step_2)
th_3 = Thread(target=step_3)
