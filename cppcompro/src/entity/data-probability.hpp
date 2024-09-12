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
    vector<int> pre_data; // stowed number from database array 1-35 1-12
    vector<int> rear_data;
    // data;
    vector<vector<int>> source_data;
    vector<vector<int>> data; // pre -> 0-4(1-5), rear -> 5-6(6-7)
    vector<vector<double>> rate;
    vector<int> openTime; // temp
public:
    void setSourceData(vector<int>);
    void setPreRearBOnce(vector<int>);
    void setNumRate();
    vector<int> * getPreNum();
    vector<int> * getRearNum();
    DataSample();
    ~DataSample();
};
DataSample::DataSample() {
    printTime();
    pre_data = vector<int>(31,0);
    rear_data = vector<int>(11,0);
    // set pre_data_pai
    data.push_back(pre_data);
    data.push_back(pre_data);
    data.push_back(pre_data);
    data.push_back(pre_data);
    data.push_back(pre_data);
    // set rear_data_pai
    data.push_back(rear_data);
    data.push_back(rear_data);
    cout << "object DataSample is being created ..." << endl;

}
void DataSample::setSourceData(vector<int> item_data){
    printTime();
    cout << "set source data" << endl;
    this->source_data.push_back(item_data); // for n item.
}

void setPreRearBOnce(vector<int> data) {
    // get data from outer.
}
void DataSample::setNumRate() {
    printTime();
    // loop source_data
    int pre = -1,rear = 4;
    cout << "Start count number and compute rate..." << endl;
    for (auto item : this->source_data) {
        // 前 5 个数字， 和后 2 个数字，对应couinter 的 外层数量(7)，
        // 内层数量 前 5 个 35-4=31， 后 2 个 12 - 1 = 11
        for (int i = 0; i < 5; i++){
            this->data[i][item[i]-i+pre] ++;
//            cout << "(" << i << "," << item[i]-i+pre << ")" <<  this->data[i][item[i]-i+pre] ++ << " ";
        }
        for (int i = 5;i < 7;i++) {
            this->data[i][item[i]-i+rear] ++;
//            cout << "(" << i << "," << item[i]-i+rear << ")" <<  this->data[i][item[i]-i+rear] ++ << " ";
        }
//        cout << endl;
    }
    int count_Sample = int (this->source_data.size());

    for (int i = 0; i < 7; i ++) {
        int count_data = int (data[i].size());
        for (int j = 0; j < count_data; j ++) {
            cout << data[i][j] << " ";
            rate[i].push_back(round((data[i][j] / count_Sample) * 100.0) / 100);
        }
        // 输出检验
        std::ostream_iterator<int> iterator(std::cout, ",");
        vector<double> tmp = rate[i];
        std::copy(tmp.begin(),tmp.end(),iterator);
        cout << endl;
    }
    cout << "success !" << endl;

}
vector<int> * DataSample::getPreNum() {
    return & this->pre_data;
}

vector<int> * DataSample::getRearNum() {
    return & this->rear_data;
}
DataSample::~DataSample () {
    printTime();
    cout << "object DataSample is being deleted!" << endl;
}

#endif //WEBREP_PY_DATA_PROBABILITY_HPP
