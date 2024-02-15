import pymongo
import pyrep.config.mongo_config as db_cfg
client = db_cfg.mongo_client
database = db_cfg.mongo_database


def connect():
    return pymongo.MongoClient(client)[database]
