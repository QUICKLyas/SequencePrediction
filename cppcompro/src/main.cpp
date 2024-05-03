#include <iostream>
#include "user.h"
using namespace std;
#include "mongo-con.hpp"

int main()
{
    cout << " start " << endl;
    MonCXX monCxx = MonCXX();
    monCxx.connectDB();
    monCxx.connectCol();
}


//}
//return 0;