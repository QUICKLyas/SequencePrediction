#include <iostream>

using namespace std;

//#include <bsoncxx/json.hpp>
//#include <mongocxx/client.hpp>
//#include <mongocxx/instance.hpp>
int main()
{

}

//// create an instance
//mongocxx::instance inst{};
//// set uri
//const auto uri = mongocxx::uri{"mongodb://root:345789%40Quickly@localhost:27017"};
//// set the version of the Stable API on the client
//mongocxx::options::client client_options;
//const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
//client_options.server_api_opts(api);
//// Set up the connection and get a handle on the database
//mongocxx::client conn{uri, client_options};
//for (auto item : conn.list_database_names()) {
//cout << item << endl;
//}
//return 0;