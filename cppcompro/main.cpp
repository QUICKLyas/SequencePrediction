#include <iostream>
#include <bson.h>
#include <mongoc.h>
using namespace std;

int main() {
    mongoc_client_t      *client;
    mongoc_database_t    *database;
    mongoc_collection_t  *collection;
    bson_t               *command,
            reply,
            *insert;
    bson_error_t          error;
    char                 *str;
    bool                  retval;

    /*
     * 初始化libmongoc's
     */
    mongoc_init ();

    /*
     * 创建一个新的client实例
     */
    client = mongoc_client_new ("");

    /*
     * 获取数据库"db_name"和集合"coll_name"的句柄
     */
    database = mongoc_client_get_database (client, "gamble");
    collection = mongoc_client_get_collection (client, "gamble", "issue");

    /*
     * 执行操作。此处以执行ping数据库，以json格式打印结果。并执行一个插入操作。
     */

    // 执行命令操作(ping)
    command = BCON_NEW ("ping", BCON_INT32 (1));
    retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);

    if (!retval) {
        fprintf (stderr, "%s\n", error.message);
        return EXIT_FAILURE;
    }
    // 获取json形式的结果
    str = bson_as_json (&reply, NULL);
    printf ("%s\n", str);	// 打印输出

    // 插入操作命令
    insert = BCON_NEW ("hello", BCON_UTF8 ("world"));

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, insert, NULL, &error)) {
        fprintf (stderr, "%s\n", error.message);
    }

    // 释放资源
    bson_destroy (insert);
    bson_destroy (&reply);
    bson_destroy (command);
    bson_free (str);

    /*
     * 释放拥有的句柄并清理libmongoc
     */
    mongoc_collection_destroy (collection);
    mongoc_database_destroy (database);
    mongoc_client_destroy (client);
    mongoc_cleanup ();
    return 0;
}
//mongocxx::uri uri{"mongodb://root:345789%40Quickly@localhost:27017"};
//// 创建一个client客户端
//mongocxx::client client = mongocxx::client{uri};
//mongocxx::database db = client["db"];
//mongocxx::collection coll = db["coll"];

//mongoc_database_t    *database;
//mongoc_collection_t  *collection;
//bson_t               *command,
//        reply,
//        *insert;
//bson_error_t          error;
//char                 *str;
//bool                  retval;
//
///*
// * 初始化libmongoc's
// */
//
//
///*
// * 创建一个新的client实例
// */
//client = mongoc_client_new ("mongodb://root:345789%40Quickly@localhost:27017");
////    for (auto item : client)
//cout << mongoc_client_get_write_concern(client);
///*
// * 获取数据库"db_name"和集合"coll_name"的句柄
// */
//database = mongoc_client_get_database (client, "gamble");
//collection = mongoc_client_get_collection (client, "gamble", "issue");
