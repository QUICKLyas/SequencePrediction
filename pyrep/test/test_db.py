import unittest
from pyrep.reptile.db import DB
from pyrep.util.file import read_json_file


class TestCase(unittest.TestCase):
    def test_insert_list_data(self, db=DB()):
        db.insert_list_data(read_json_file())
        self.assertEqual(True, True)  # add assertion here

    def test_remove_list_data(self, db=DB()):
        db.drop_one_coll()
        self.assertEqual(True, True)  # add assertion here

    def test_update_old_list_data(self, db=DB()):
        db.update_new_list_data()
        self.assertEqual(True, True)


if __name__ == '__main__':
    unittest.main()
