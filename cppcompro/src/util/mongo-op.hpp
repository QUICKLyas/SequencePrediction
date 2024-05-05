//
// Created by Administrator on 2024/5/3.
//

#ifndef WEBREP_PY_MONGO_OPERATOR_HPP
#define WEBREP_PY_MONGO_OPERATOR_HPP
#include <iostream>

#include <mongocxx/collection.hpp>
using namespace std;
using namespace mongocxx;
// abstract class
class MonCxxOP;
class MonCOP;

class MonCxxOP{
private:

public:
    // find
    auto insertOneDoc();
    auto insertMulDoc();
    // find
    auto findSingleDoc(collection &);
    auto findAllDoc();
    auto printAllDoc();
    auto findByFilter();
    // update
    auto updateSingleDoc();
    auto updateMulDoc();
    //delete
    auto deleteSinDocument();
    auto DeleteAllDocByFilter();
    MonCxxOP();
    ~MonCxxOP();

};
MonCxxOP::MonCxxOP() {
    cout << "object MonCxxOP is being created!" << endl;
}
auto MonCxxOP::findSingleDoc(collection & col) {
    auto find_one_result = col.find_one({});
    if (find_one_result) {
        // TODO
    }
}
MonCxxOP::~MonCxxOP() {
    cout << "object MonCxxOP is being deleted!" << endl;
}
#endif //WEBREP_PY_MONGO_OPERATOR_HPP
