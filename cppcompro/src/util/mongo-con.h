//
// Created by Administrator on 2024/4/30.
//

#ifndef WEBREP_PY_MONGO_CON_H
#define WEBREP_PY_MONGO_CON_H
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
#include "owner-timer.h"
// create abstract Class MonC & MonCXX
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

using namespace mongocxx;
// abstract class
class MonC;
class MonCXX;

class MonCXX{
private:
    // SCRAM-SHA-1
    std::string user = USER;
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
    collection * getCollection();
    database * getDatabase();
    MonCXX();
    ~MonCXX();
};
MonCXX::MonCXX() {
    printTime();
    std::cout << "object MonCXX is being created ..." << std::endl;
    connect_uri = uri(URI);
    single_client = client(connect_uri);
}
database * MonCXX::connectDB(bsoncxx::string::view_or_value db_name = CUR_DB) {
    printTime();
    std::cout << "connect to database: " << db_name.data() << " ... ";
    this->db = single_client.database(db_name);
    std::cout << "success." << std::endl;
    return & this->db;
}
collection * MonCXX::connectCol(bsoncxx::string::view_or_value coll_name = CUR_COLLECTION) {
    printTime();
    std::cout << "connect to collection: " << coll_name.data() << " ... ";
    this->col = this->db.collection(coll_name);
    std::cout << "success." << std::endl;
    return & this->col;
}
collection * MonCXX::connectColBOnce(
            bsoncxx::string::view_or_value db_name = CUR_DB,
            bsoncxx::string::view_or_value coll_name = CUR_COLLECTION) {

    printTime();
    std::cout << "connect to collection: " << db_name.data() << "->" << coll_name.data() << " ... " << std::endl;
    this->db = * this->connectDB(db_name);
    this->col = * this->connectCol(coll_name);
    return & this->col;
}

database * MonCXX::getDatabase() {
    std::cout << "get the address of database: " << this->db.name().data() << "->" << & this->db << std::endl;
    return & this->db;
}
collection * MonCXX::getCollection() {
    std::cout << "get the address of collection: " << this->col.name().data() << "->"  << & this->col << std::endl;
    return & this->col;

}

MonCXX::~MonCXX(){
    printTime();
    std::cout << "object MonCXX is being deleted!" << std::endl;
}

class MonC{
private:
public:
    MonC();
    ~MonC();
};
MonC::MonC(){
    printTime();
    std::cout << "object MonC is being created" << std::endl;
}
MonC::~MonC(){
    printTime();
    std::cout << "object MonC is being deleted!" << std::endl;
}
#endif //WEBREP_PY_MONGO_CON_H
