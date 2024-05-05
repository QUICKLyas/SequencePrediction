#include <iostream>
#include "user.h"
using namespace std;
#include "mongo-con.hpp"
#include "mongo-op.hpp"
int main()
{
//    mongocxx::instance instance{};
//    mongocxx::client client{mongocxx::uri{"mongodb://root:345789%40Quickly@localhost:27017"}};
//    mongocxx::database db = client.database("gamble");
//    mongocxx::collection col = db.collection("issue");
    MonCXX monCxx = MonCXX();
    MonCxxOP monCxxOp = MonCxxOP();
    monCxx.connectDB();
    collection * col = monCxx.connectCol();
    monCxxOp.findSingleDoc(*col);

}


//}
//return 0;