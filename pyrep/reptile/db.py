import pymongo
from pyrep.util import mongo
from pyrep.util.file import delete_json_file as djf
# get message from db (mongo)


class DB:
    database = None

    def __init__(self):
        self.database = mongo.connect()
        pass

    # insert list_data. After, pro should delete data from file: dataKJHM.json
    def insert_list_data(self, list_data: list = None, collection='issue') -> bool:
        # insert into db
        coll = self.database['issue']
        coll.insert_many(list_data)
        djf() # 默认删除读取的文件内容
        return True

    def drop_one_coll(self, collection='issue') -> bool:
        self.database.drop_collection(collection)
        return True
