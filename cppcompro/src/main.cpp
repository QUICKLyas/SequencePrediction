#include <iostream>

using namespace std;
#include "mongo-con.hpp"

int main()
{
    MonCXX monCxx = MonCXX();
    auto db = monCxx.setCFromP()['gamble'];
    auto collection = db['issue'];
}


//}
//return 0;