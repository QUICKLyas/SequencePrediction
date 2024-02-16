from urllib.parse import quote_plus
mongo_user = quote_plus("root")
mongo_pass = quote_plus("345789@Quickly")
mongo_client = 'mongodb://{0}:{1}@localhost:27017/'.format(mongo_user,mongo_pass)
mongo_database = 'gamble'
mongo_collection = "issue"
