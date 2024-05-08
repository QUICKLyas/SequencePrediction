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
    monCxxOp.getAllNumFromDataS(answer_pre, answer_rear);

    for (vector <int> item : answer_pre) {
        for (int item_num : item) {
            cout << item_num << " ";
        }
        cout << endl;
    }

    for (vector <int> item : answer_rear) {
        for (int item_num : item) {
            cout << item_num << " ";
        }
        cout << endl;

    }
    return 0;
}