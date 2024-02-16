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
    def insert_list_data(self, collection='issue') -> dict:
        # insert into db
        dict_return: dict = {}
        dict_return = read_json_file()
        coll = self.database['issue']
        coll.insert_many(dict_return.get("data"))
        delete_json_file_data()  # 默认删除读取的文件内容
        return dict_return

    # 暂定不需要使用这个，一般用于test中清除数据
    def drop_one_coll(self, collection='issue') -> bool:
        self.database.drop_collection(collection)
        return True
