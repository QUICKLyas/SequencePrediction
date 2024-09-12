import unittest
from threading import Condition

import pyrep.reptile.prothread as pt

condition = Condition()


class MyTestCase(unittest.TestCase):

    def test_web_thread(self):
        thread1 = pt.WebRepThread(1,"WebRepThread",0, condition)
        pt.start_thread(thread1)

    def test_db_thread(self):
        thread3 = pt.DBThread(3, "DBThread",condition)
        pt.start_thread(thread3)
        self.assertEqual(True, True)  # add assertion here


if __name__ == '__main__':
    unittest.main()
