//
// Created by Administrator on 2024/5/3.
//

#ifndef WEBREP_PY_MONGO_OPERATOR_HPP
#define WEBREP_PY_MONGO_OPERATOR_HPP
#include <iostream>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>

#include "owner-timer.h"
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
    static bool insertOneDoc(collection &, const bsoncxx::document::value&);
    bool insertMulDoc(collection &, const std::vector<bsoncxx::document::value>&);
    // find
    auto findSingleDoc(MonCXX &);
    auto findAllDoc(MonCXX &);
    auto printDoc(cursor & );
    auto findByFilter();
    // update
    bool updateSingleDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    bool updateMulDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    //delete
    bool delSinDoc(collection &, bsoncxx::document::view_or_value);
    bool delAllDocByF(collection &, bsoncxx::document::view_or_value);
    // index -- improve query efficiency
    MonCxxOP();
    ~MonCxxOP();

};
MonCxxOP::MonCxxOP() {
    printTime();
    std::cout << "object MonCxxOP is being created!" << std::endl;
}
auto MonCxxOP::printDoc(mongocxx::cursor & list_cursor) {
    printTime();
    std::cout << "<=" << std::endl;
    for (auto doc : list_cursor) {
        // TODO
        printTime();
        assert(doc["_id"].type() == bsoncxx::type::k_oid);
        std::cout << "\t\t" << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
    }
}
auto MonCxxOP::findSingleDoc(MonCXX & monCxx) {
    printTime();
    bsoncxx::stdx::optional<bsoncxx::document::value> find_one_result = (*monCxx.getCollection()).find_one({});
    assert(find_one_result);
    if (find_one_result) {
        // TODO
    }
    return find_one_result;
}
auto MonCxxOP::findAllDoc(MonCXX & monCxx){
    auto cursor_all = monCxx.getCollection()->find({});
//    assert(std::count(cursor_all.begin(), cursor_all.end()));
    std::cout << "collection " << monCxx.getCollection()->name()
         << " contains these documents:" << std::endl;
    for (auto doc : cursor_all) {
        std::cout << "\t\t" << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
    }
    return cursor_all;
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
bool MonCxxOP::insertMulDoc(mongocxx::collection & col, const std::vector<bsoncxx::document::value>& documents) {
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
    assert(update_many_result);
    assert(update_many_result->upserted_count() > 0);
    bool flag = (update_many_result->upserted_count() > 0);
    return flag;
}
bool MonCxxOP::delSinDoc(collection & col, bsoncxx::document::view_or_value doc_filter) {
    auto delete_one_result = col.delete_one(std::move(doc_filter));
    assert(delete_one_result);
    assert(delete_one_result->deleted_count() == 1);
    bool flag = (delete_one_result->deleted_count() == 1);
    return flag;
}
bool MonCxxOP::delAllDocByF(collection & col, bsoncxx::document::view_or_value doc_filter) {
    auto delete_many_result = col.delete_many(std::move(doc_filter));
    assert(delete_many_result);
    assert(delete_many_result->deleted_count() > 0);
    bool flag = (delete_many_result->deleted_count() > 0);
    return flag;
}

MonCxxOP::~MonCxxOP() {
    printTime();
    std::cout << "object MonCxxOP is being deleted!" << std::endl;
}
#endif //WEBREP_PY_MONGO_OPERATOR_HPP
