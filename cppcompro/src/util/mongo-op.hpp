//
// Created by Administrator on 2024/5/3.
//

#ifndef WEBREP_PY_MONGO_OPERATOR_HPP
#define WEBREP_PY_MONGO_OPERATOR_HPP
#include <iostream>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>
#include <utility>
#include "mongo-con.h"
#include "owner-timer.h"
using namespace mongocxx;
// abstract class
class MonCxxOP;
class MonCOP;

class MonCxxOP{
private:
    std::vector<std::vector<int>> pre_data; // stowed number from database array 1-35 1-12
    std::vector<std::vector<int>> rear_data;
public:
    // find
    /*
     * return answer about operation is success (true/false)
     */
    static bool insertOneDoc(collection &, const bsoncxx::document::value&);
    bool insertMulDoc(collection &, const std::vector<bsoncxx::document::value>&);
    // find
    auto findSingleDoc(mongocxx::collection &, bsoncxx::document::view_or_value);
    auto findAllDoc(mongocxx::collection &,  bsoncxx::document::view_or_value, const int);
    void printDoc(const bsoncxx::document::view &);
    auto printBatchDoc(cursor);
    auto findByFilter();
    // update
    bool updateSingleDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    bool updateMulDoc(collection &, bsoncxx::document::view_or_value, bsoncxx::document::view_or_value);
    //delete
    bool delSinDoc(collection &, bsoncxx::document::view_or_value);
    bool delAllDocByF(collection &, bsoncxx::document::view_or_value);
    // index -- improve query efficiency

    friend class MonCXX;

    MonCxxOP();
    ~MonCxxOP();

};
MonCxxOP::MonCxxOP() {
    printTime();
    std::cout << "object MonCxxOP is being created!" << std::endl;
}

void MonCxxOP::printDoc(const bsoncxx::document::view & doc) {
    /*
     * three item : issue | openTime | WinnningNum(Array)
     */
    std::string issue = doc["issue"].get_string().value.to_string();
    std::string openTime = doc["openTime"].get_string().value.to_string();
    auto tmpWinNum = doc["WinningNum"].get_array();
    std::vector<int> winNum;
    for (auto & item : tmpWinNum.value) {
        int num = item.get_int32();
        winNum.push_back(num);
    }
    std::ostream_iterator<int> iterator(std::cout, ",");
    std::cout << "[" << issue << "] \t [" << openTime << "] \t [";
    std::copy(winNum.begin(), winNum.end(), iterator);
    std::cout << "]" << std::endl;
}
auto MonCxxOP::printBatchDoc(cursor cursor_a) {
    if (cursor_a.begin() != cursor_a.end()) {
        for (const bsoncxx::document::view doc : cursor_a) {
            printDoc(doc);
        }
    }
}
auto MonCxxOP::findSingleDoc(mongocxx::collection & coll, bsoncxx::document::view_or_value filter) {
    printTime();
    bsoncxx::stdx::optional<bsoncxx::document::value> find_one_result = coll.find_one({});
    assert(find_one_result);
    if (find_one_result) {
        // TODO
    }
    return find_one_result;
}
auto MonCxxOP::findAllDoc(mongocxx::collection & coll, bsoncxx::document::view_or_value filter,const int skip_pages){
    printTime();
    options::find options = options::find().limit(30).skip(skip_pages);
    cursor cursor_all = coll.find(std::move(filter), options);
    std::cout << "collection " << coll.name()
         << " contains these documents:" << std::endl;
    printBatchDoc( coll.find(std::move(filter), options));
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
