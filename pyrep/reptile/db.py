import pymongo
from pymongo import collection
from bson.json_util import dumps

from pyrep.util import mongo
from pyrep.util.file import delete_json_file_data, read_json_file


# get message from db (mongo)


class DB:
    database = None

    def __init__(self):
        self.database = mongo.connect()
        self.coll = self.database['issue']
        pass

    # insert list_data. After, pro should delete data from file: dataKJHM.json
    def insert_list_data(self, collection_name='issue') -> dict:
        # insert into db
        dict_return: dict = {}
        dict_return = read_json_file()
        self.coll = self.database[collection_name]
        self.coll.insert_many(dict_return.get("data"))
        delete_json_file_data()  # 默认删除读取的文件内容
        return dict_return

    def update_new_list_data(self, collection_name='issue') -> dict:
        # update into db
        dict_return: dict = {}
        dict_return = read_json_file()
        # connect to database issue
        self.coll = self.database[collection_name]
        list_data = dict_return.get("data")
        for item in list_data:
            filter_item = {'issue': item['issue']}
            # 更新，存在就更新，不存在就插入
            self.coll.update_one(filter_item, {'$set': item}, upsert=True)
        delete_json_file_data()  # 默认删除读取的文件内容
        return dict_return

    def drop_old_list_data(self, filter_example: dict) -> bool:
        self.coll.drop(filter_example)
        return True

    # 暂定不需要使用这个，一般用于test中清除数据
    def drop_one_coll(self, collection_name='issue') -> bool:
        self.database.drop_collection(collection)
        return True
