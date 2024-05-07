#include "mongo-con.h"
#include "mongo-op.hpp"
//#include "owner-timer.h"
using namespace std;
int main()
{
    MonCXX monCxx ;
    MonCxxOP monCxxOp;
    monCxx.connectDB();
    monCxxOp.findAllDoc(monCxx);
    return 0;
}