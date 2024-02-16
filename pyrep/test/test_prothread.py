import unittest
import pyrep.reptile.prothread as pt


class MyTestCase(unittest.TestCase):
    def test_get_html_text(self):
        thread1 = pt.WebRepThreadGetSpringText(1, "WebRepThreadGetSpringText", 0)
        pt.start_thread(thread1)
        pt.end_thread(thread1)
        self.assertEqual(True,True)

    def test_parse_text(self):
        thread2 = pt.WebRepThreadParseText(2, "WebRepThreadParseText")
        pt.start_thread(thread2)
        pt.end_thread(thread2)
        self.assertEqual(True, True)  # add assertion here

    def test_db_thread(self):
        thread3 = pt.DBThread(3, "DBThread")
        pt.start_thread(thread3)
        pt.end_thread(thread3)
        self.assertEqual(True, True)  # add assertion here


if __name__ == '__main__':
    unittest.main()
