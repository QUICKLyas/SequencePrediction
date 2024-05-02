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

#include "user.h"
// create abstract Class MonC & MonCXX
// class for configuring the connector pool and setting
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

using namespace std;
using namespace mongocxx;
class MonC;
class MonCXX;
class MonCXX{
private:
    // SCRAM-SHA-1
    string user = USER;
    string passwd = PASSWD;
    instance inst;
    client single_client;
    uri connect_uri;
//    client single_client;
//    pool pool_clients = mongocxx::pool{uri{"mongodb://"+
//    user + ":" + passwd +
//    "@localhost/?authSource=db1&authMechanism=SCRAM-SHA-1" +
//    "&minPoolSize=3&maxPoolSize=5"}};
//    mongocxx::instance instance{};
public:
    auto connectCollection(client currentClient);
    client * getClient();
    MonCXX(){
        mongocxx::instance instance{};
        cout << "1-1" <<endl;
        mongocxx::uri connect_uri ("mongodb://" + user + ":" + passwd + "@localhost:27017");
        cout << "1-2" <<endl;
        mongocxx::client client(connect_uri);
        cout << "1-3" <<endl;
    }
};
class MonC{

};
//auto MonCXX::createCFromP() {
//    auto new_client = this->pool_clients.acquire();
//    return new_client;
//}
auto MonCXX::connectCollection(mongocxx::client currentClient) {
    return currentClient[CUR_DB];
}
client * MonCXX::getClient() {
    cout << this->single_client.uri().to_string();
    client * answer = & (this->single_client);
    return answer;
}


#endif //WEBREP_PY_MONGO_CON_HPP
