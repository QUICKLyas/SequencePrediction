//
// Created by Administrator on 2024/4/30.
//

#ifndef WEBREP_PY_MONGO_CON_HPP
#define WEBREP_PY_MONGO_CON_HPP
#include <string>
#include <vector>
#include <iostream>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx//uri.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/instance.hpp>
// get user message to connect database.
#include "user.h"
// create abstract Class MonC & MonCXX
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

using namespace std;
using namespace mongocxx;
// abstract class
class MonC;
class MonCXX;

class MonCXX{
private:
    // SCRAM-SHA-1
    string user = USER;
    instance instance{}; // this should be done only once in constructor
    client single_client; // client
    uri connect_uri; // connect uri
    database db; // stowed database
    collection col; // stowed collection
public:
    auto connectDB(string);// get database connection by database name(string)
    auto connectCol(string); // get collection connection by collection name (string)
    MonCXX();
    ~MonCXX();
};
MonCXX::MonCXX() {
    cout << "object is being created" <<endl;
    connect_uri = uri(URI);
    single_client = client(connect_uri);
}
auto MonCXX::connectDB(string db_name = CUR_DB) {
    cout << "connect to database: " << CUR_DB << "...";
    this->db = single_client[db_name];
    cout << "success." << endl;
    return this->db;
}
auto MonCXX::connectCol(string coll_name = CUR_COLLECTION) {
    cout << "connect to collection: " << CUR_COLLECTION << "...";
    this->col = this->db[CUR_COLLECTION];
    cout << "success." << endl;
    return this->col;
}
MonCXX::~MonCXX(){
    cout << "object is being deleted!" << endl;
}
class MonC{
private:
public:
    MonC();
    ~MonC();
};
MonC::MonC(){
    cout << "object is being created" <<endl;
}
MonC::~MonC(){
    cout << "object is being deleted!" << endl;
}
#endif //WEBREP_PY_MONGO_CON_HPP
