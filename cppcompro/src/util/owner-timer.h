//
// Created by Administrator on 2024/5/5.
//

#ifndef WEBREP_PY_OWNER_TIMER_H
#define WEBREP_PY_OWNER_TIMER_H

#include <string>
#include <iostream>
using namespace std;
#ifdef linux
#include <unistd.h>
#include <pwd.h>
#endif
// now only for windows
#ifdef _WIN64
#include<Windows.h>
#endif
// abstract function
string getPcName();
void getUserName();

string getPcName() {

#if defined _WIN64
    const int MAX_LEN = 4;
    char szBuffer[MAX_LEN];
    DWORD len = MAX_LEN;
    GetComputerNameA(szBuffer, & len);
#else
    szBuffer = "";
#endif
    cout << szBuffer;
}
void getUserName() {
#if defined _WIN64
    const int MAX_LEN = 255;
    char szBuffer[MAX_LEN];
    DWORD len = MAX_LEN;
    GetUserName(szBuffer, &len);
#else // outher system
    szBuffer = "";
#endif
    cout << szBuffer ;
}
#endif //WEBREP_PY_OWNER_TIMER_H
