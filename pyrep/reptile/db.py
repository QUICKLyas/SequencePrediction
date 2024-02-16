import pymongo
from pyrep.util import mongo
from pyrep.util.file import delete_json_file_data, read_json_file
# get message from db (mongo)


class DB:
    database = None

    def __init__(self):
        self.database = mongo.connect()
        pass

    # insert list_data. After, pro should delete data from file: dataKJHM.json
    def insert_list_data(self, collection='issue') -> bool:
        # insert into db
        list_data = read_json_file()
        if len(list_data) == 0:
            return False
        coll = self.database['issue']
        coll.insert_many(list_data)
        delete_json_file_data()  # 默认删除读取的文件内容
        return True

    def drop_one_coll(self, collection='issue') -> bool:
        self.database.drop_collection(collection)
        return True
