#include "mongo-con.hpp"
#include "mongo-op.hpp"
//#include "owner-timer.h"
using namespace std;
int main()
{
    MonCXX monCxx ;
    MonCxxOP monCxxOp;
    monCxx.connectDB();
    monCxx.connectCol();
    vector<vector<int>> answer_pre;
    vector<vector<int>> answer_rear;
    monCxxOp.findAllDoc((*monCxx.getCollection()), {},30);
    monCxxOp.getDataSample()->setNumRate();
    return 0;
}