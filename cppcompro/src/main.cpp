#include <iostream>

using namespace std;

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include "util/mongoc-cxx.hpp"
int main()
{
    MongoC *mongoC = new MongoC("root","345789@Quickly");
    mongoC->connectDB("gamble");
}


//}
//return 0;