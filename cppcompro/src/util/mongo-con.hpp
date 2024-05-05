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
    database * connectDB(bsoncxx::string::view_or_value);// get database connection by database name(string)
    collection * connectCol(bsoncxx::string::view_or_value); // get collection connection by collection name (string)
    collection * connectColBOnce(bsoncxx::string::view_or_value,
                                 bsoncxx::string::view_or_value); // connect by one step
    // op
    /*
     *
     */
    auto opFindSingleDoc(collection &);
    MonCXX();
    ~MonCXX();
};
MonCXX::MonCXX() {
    cout << "object MonCXX is being created..." << endl;
    connect_uri = uri(URI);
    single_client = client(connect_uri);
}
database * MonCXX::connectDB(bsoncxx::string::view_or_value db_name = CUR_DB) {
    cout << "connect to database: " << db_name.data() << "...";
    this->db = single_client.database(db_name);
    cout << "success." << endl;
    return & this->db;
}
collection * MonCXX::connectCol(bsoncxx::string::view_or_value coll_name = CUR_COLLECTION) {
    cout << "connect to collection: " << coll_name.data() << "...";
    this->col = this->db.collection(coll_name);
    cout << "success." << endl;
    return & this->col;
}
collection * MonCXX::connectColBOnce(
        bsoncxx::string::view_or_value db_name = CUR_DB,
        bsoncxx::string::view_or_value coll_name = CUR_COLLECTION) {
    cout << "connect to collection: " << db_name.data() << "->" << coll_name.data() << "...";
    this->db = * this->connectDB(db_name);
    this->col = * this->connectCol(coll_name);
    return & this->col;
}

MonCXX::~MonCXX(){
    cout << "object MonCXX is being deleted!" << endl;
}
class MonC{
private:
public:
    MonC();
    ~MonC();
};
MonC::MonC(){
    cout << "object MonC is being created" <<endl;
}
MonC::~MonC(){
    cout << "object MonC is being deleted!" << endl;
}
#endif //WEBREP_PY_MONGO_CON_HPP
