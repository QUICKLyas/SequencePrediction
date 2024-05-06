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
    /*
     * return answer about operation is success (true/false)
     */
    bool insertOneDoc(collection &, const bsoncxx::document::value&);
    bool insertMulDoc(collection &, const vector<bsoncxx::document::value>&);
    // find
    auto findSingleDoc(collection &);
    auto findAllDoc(collection &);
    auto printDoc(cursor & );
    auto findByFilter();
    // update
    bool updateSingleDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    bool updateMulDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    //delete
    bool delSinDoc(collection &, bsoncxx::document::view_or_value);
    bool delAllDocByF(collection &, bsoncxx::document::view_or_value);
    // idnex -- improve query efficiency
    MonCxxOP();
    ~MonCxxOP();

};
MonCxxOP::MonCxxOP() {
    cout << "object MonCxxOP is being created!" << endl;
}
auto MonCxxOP::printDoc(mongocxx::cursor & list_cursor) {
    for (auto doc : list_cursor) {
        // TODO
        assert(doc["_id"].type() == bsoncxx::type::k_oid);
        cout << "\t\t" << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed);
    }
}
auto MonCxxOP::findSingleDoc(collection & col) {
    auto find_one_result = col.find_one({});
    if (find_one_result) {
        // TODO
    }
}
auto MonCxxOP::findAllDoc(collection & col) {
    cursor cursor_all = col.find({});
    cout << "collection " << col.name()
         << " contains these documents:" << endl;
    this->printDoc(cursor_all);
    cout << endl;
}
bool MonCxxOP::insertOneDoc(collection & col, const bsoncxx::document::value& filter) {
    bsoncxx::document::value json_doc = make_document(kvp("id",0));
    auto insert_one_result = col.insert_one(make_document(kvp("id",0)));
    assert(insert_one_result);
    auto doc_id = insert_one_result->inserted_id();
    assert(doc_id.type() == bsoncxx::type::k_oid);
    bool flag = (doc_id.type() == bsoncxx::type::k_oid);
    return flag;
}
bool MonCxxOP::insertMulDoc(mongocxx::collection & col, const vector<bsoncxx::document::value>& documents) {
    bool flag = false;
    auto insert_many_result = col.insert_many(documents);
    assert (insert_many_result);
    if (insert_many_result) {
        flag = true;
    }
    return flag;
}
bool MonCxxOP::updateSingleDoc(collection & col,
                     bsoncxx::document::view_or_value doc_filter,
                     bsoncxx::document::view_or_value doc_update){
    auto update_one_result =  col.update_many(doc_filter, doc_update);
    assert(update_one_result);
    assert(update_one_result->modified_count() == 1);
    bool flag = (update_one_result->modified_count() == 1);
    return flag;
}
bool MonCxxOP::updateMulDoc(collection & col,
                            bsoncxx::document::view_or_value doc_filter,
                            bsoncxx::document::view_or_value docs_update) {
    auto update_many_result = col.update_many(doc_filter, docs_update);
}
bool MonCxxOP::delSinDoc(collection & col, bsoncxx::document::view_or_value doc_filter) {
    auto delete_one_result = col.delete_one(doc_filter);
    assert(delete_one_result);
    assert(delete_one_result->deleted_count() == 1);
    bool flag = (delete_one_result->deleted_count() == 1);
    return flag;
}
bool MonCxxOP::delAllDocByF(collection & col, bsoncxx::document::view_or_value doc_filter) {
    auto delete_many_result = col.delete_many(doc_filter);
    assert(delete_many_result);
    assert(delete_many_result->deleted_count() > 0);
    bool flag = (delete_many_result->deleted_count() > 0);
    return flag;
}

MonCxxOP::~MonCxxOP() {
    cout << "object MonCxxOP is being deleted!" << endl;
}
#endif //WEBREP_PY_MONGO_OPERATOR_HPP
