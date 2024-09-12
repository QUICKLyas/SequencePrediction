import pymongo
import src.config.mongo_config as db_cfg


def connect():
    return pymongo.MongoClient(db_cfg.mongo_client)[db_cfg.mongo_database]
