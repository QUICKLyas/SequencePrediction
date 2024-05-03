#include <iostream>
#include "user.h"
using namespace std;
#include "mongo-con.hpp"
#include "mongo-op.hpp"
int main()
{
    cout << " start " << endl;
    MonCXX monCxx = MonCXX();
    monCxx.connectDB();
    collection col = monCxx.connectCol();
//    auto doc_value = make_document(
//            kvp("issue","24045"),
//            kvp("openTime","2024-04-22"),
//            kvp("WinningNum", make_array("9","10","14","31","32","3","8"))
//            );
//    auto doc_view = doc_value.view();
//    auto element = doc_view["issue"];
//    assert(element.type() == bsoncxx::type::k_string);
//    auto name = element.get_string().value;
//    assert(0 == name.compare("24035"));
    bsoncxx::stdx::optional<bsoncxx::document::value> find_one_result = col.find_one({});
    bsoncxx::document::view view2 = find_one_result->view();
    auto find_one_id = view2["_id"].get_oid().value.to_string();
    cout << "\nfind one document, return id is " << find_one_id << endl;
//    auto cursor = col.find({});
//    for (auto && document : cursor) {
//        cout << bsoncxx::to_json(document) << endl;
//    }

//    monCxxOp.findSingleDoc(monCxx.connectCol());
}


//}
//return 0;