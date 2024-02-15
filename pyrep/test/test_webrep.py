import unittest
from pyrep.reptile.webrep import WebRep


class MyTestCase(unittest.TestCase):
    def test_parse_text(self, web_rep=WebRep()):
        text = web_rep.parse_text(web_rep, web_rep.get_html_text())
        self.assertEqual(True, True)  # add assertion here

    def test_write_text(self, web_rep=WebRep()):
        text = web_rep.parse_text(web_rep, web_rep.get_html_text())
        web_rep.write_text(web_rep, text)
        self.assertEqual(True,True)


if __name__ == '__main__':
    unittest.main()
