//
// Created by Administrator on 2024/5/8.
//

#ifndef WEBREP_PY_DATA_PROBABILITY_HPP
#define WEBREP_PY_DATA_PROBABILITY_HPP
#include <vector>
#include <iostream>

#include "owner-timer.h"
using namespace std;
class DataSample;

class DataSample {
private:
    vector<vector<int>> pre_data; // stowed number from database array 1-35 1-12
    vector<vector<int>> rear_data;
    vector<int> openTime; // temp
public:
    void setPreNum(vector<int>);
    void setRearNum(vector<int>);
    vector<vector<int>> * getPreNum();
    vector<vector<int>> * getRearNum();
    DataSample();
    ~DataSample();
};
DataSample::DataSample() {
    printTime();
    cout << "object DataSample is being created ..." << endl;
}
void DataSample::setPreNum(vector<int> item_pre_data){
    this->pre_data.push_back(item_pre_data);
}

void DataSample::setRearNum(vector<int> item_rear_data) {
    this->pre_data.push_back(item_rear_data);
}

vector<vector<int>> * DataSample::getPreNum() {
    return & this->pre_data;
}

vector<vector<int>> * DataSample::getRearNum() {
    return & this->rear_data;
}
DataSample::~DataSample () {
    printTime();
    cout << "object DataSample is being deleted!" << endl;
}

#endif //WEBREP_PY_DATA_PROBABILITY_HPP
