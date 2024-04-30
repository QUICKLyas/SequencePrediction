//
// Created by Administrator on 2024/4/30.
//

#ifndef WEBREP_PY_MONGO_CON_HPP
#define WEBREP_PY_MONGO_CON_HPP
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx//uri.hpp>
#include <mongocxx/pool.hpp>

#include "user.h"
// create abstract Class MonC & MonCXX
// class for configuring the connector pool and setting

using namespace std;
using namespace mongocxx;
class MonC;
class MonCXX;
class MonCXX{
private:
    // SCRAM-SHA-1
    string user = USER;
    string passwd = PASSWD;
    uri connect_uri = {};
    client single_client = {};
    pool pool_clients = mongocxx::pool{uri{"mongodb://"+
    user + ":" + passwd +
    "@host1/?authSource=db1&authMechanism=SCRAM-SHA-1" +
    "&minPoolSize=3&maxPoolSize=5"}};

public:
    auto setCFromP();

    MonCXX() {
        string str_url = "mongodb://" + user + ":" + passwd + "@host1/?authSource=db1&authMechanism=SCRAM-SHA-1";
        this->connect_uri = {str_url}; // set connect url
        // create Client;
        this->single_client = {connect_uri};
    }
};

auto MonCXX::setCFromP() {
    auto new_client = this->pool_clients.acquire();
    return new_client;
}


#endif //WEBREP_PY_MONGO_CON_HPP
