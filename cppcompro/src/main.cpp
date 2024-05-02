#include <iostream>
#include "user.h"
using namespace std;
#include "mongo-con.hpp"

int main()
{
    string user = USER;
    string passwd = PASSWD;
    cout << " start " << endl;
    mongocxx::instance instance{};
    cout << "1-1" <<endl;
    mongocxx::uri uri("mongodb://" + user + ":" + passwd + "@localhost:27017");
    cout << "1-2" <<endl;
    mongocxx::client client(uri);
    cout << "1-3" <<endl;
    cout << " 1 " << endl;
//    client * cl = monCxx->getClient();
    cout << " 2 " << endl;

    //    auto client = monCxx->createCFromP();
//    auto collection = monCxx->connectCollection(monCxx->getClient());
    cout << "..." << endl;
}


//}
//return 0;