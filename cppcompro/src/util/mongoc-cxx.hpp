//
// Created by Administrator on 2024/3/14.
//

#ifndef WEBREP_PY_MONGOC_CXX_H
#define WEBREP_PY_MONGOC_CXX_H
#include <bson.h>
#include <mongoc.h>
#include <string>
#include <iostream>

using namespace std;
// abstract function
class MongoC; // abstract class
class Datagram; // send data
// function
class MongoC {
private:
    mongoc_client_t *client = NULL;
    bson_error_t error = {0};
    mongoc_server_api_t *api = NULL;
    mongoc_database_t *database = NULL;
    bson_t *command = NULL;
    bson_t reply = BSON_INITIALIZER;
    int rc = 0;
    bool ok = true;
    const char *uri;
    Datagram *datagram;
public:
    int cleanUp();
    int setClient();
    int connectDB(const char *dbName);
    MongoC (string userName, string passwd) {
        string url = "mongodb://" + userName + ":" + passwd + "@localhost:27017";
        this->uri = url.c_str();
        // Initialize the MongoDB C Driver.
        mongoc_init();
    }
};
// Perform cleanup.
int MongoC::cleanUp() {
    bson_destroy(command);
    mongoc_database_destroy(database);
    mongoc_server_api_destroy(api);
    mongoc_client_destroy(client);
    mongoc_cleanup();
    return 0;
}
int MongoC::setClient () {
    // set client
    client = mongoc_client_new(uri);
    if (!client) {
        string str = "Failed to create a MongoDB client.\n";
        fprintf(stderr, str.c_str());
        int rc = 1;
//        datagram->set(str,1);
        cleanUp();
    }
    // Set the version of the Stable API on the client.
    api = mongoc_server_api_new(MONGOC_SERVER_API_V1);
    if (!api) {
        fprintf(stderr, "Failed to create a MongoDB server API.\n");
        rc = 1;
        cleanUp();
    }
    // config server_api to client
    ok = mongoc_client_set_server_api(client, api, &error);
    if (!ok) {
        fprintf(stderr, "error: %s\n", error.message);
        rc = 1;
        cleanUp();
    }
}
// connect database
int MongoC::connectDB(const char *dbName) {
    // Get a handle on the database.example: "admin"
    database = mongoc_client_get_database(client, dbName);
    if (!database) {
        fprintf(stderr, "Failed to get a MongoDB database handle.\n");
        rc = 1;
        cleanUp();
    }
    // Ping the database. check connection
    command = BCON_NEW("ping", BCON_INT32(1));
    ok = mongoc_database_command_simple(
            database, command, NULL, &reply, &error
    );
    if (!ok) {
        fprintf(stderr, "error: %s\n", error.message);
        rc = 1;
        cleanUp();
    }
    bson_destroy(&reply);
    printf("Pinged your deployment. You successfully connected to MongoDB!\n");
    return rc;
}
class Datagram{
public: // 仅在本文件中可以使用
    string message;
    int code ; // rc from class MongoC
    mongoc_client_t *client = NULL;
    mongoc_database_t *database = NULL;
    bson_t *command = NULL;
    Datagram() {
        this->message = "success!";
        this->code = 0; // success
    }
    void set(string str, int rc);
    void printStr();
};
// set message, code
void Datagram::set (string str, int rc) {
    this->message = str;
    this->code = rc;
}
void Datagram::printStr(){
    std::cout << "data: {"
              << "code: " << this->code << "," << endl
              << "message: " << this->message << "," << endl
              << "client: " << this->client << "," << endl
              << "database: " << this->database << "," << endl
              << "command " << this->command << "," << endl
              << "}" << std::endl;
}
#endif //WEBREP_PY_MONGOC_CXX_H
