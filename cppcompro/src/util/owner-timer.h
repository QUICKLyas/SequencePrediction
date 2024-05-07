//
// Created by Administrator on 2024/5/5.
//

#ifndef WEBREP_PY_OWNER_TIMER_H
#define WEBREP_PY_OWNER_TIMER_H

#include <string>
#include <iostream>
#ifdef linux
#include <unistd.h>
#include <pwd.h>
#endif
// now only for windows
#ifdef _WIN64
#include<Windows.h>
#endif
// abstract function
std::string getPcName();
std::string getUserName();
static void printTime();
static void printLabel();

std::string getPcName() {
    const int MAX_LEN = 5; // ARKI min -> 5
    char szBuffer[MAX_LEN];
#if defined _WIN64
    DWORD len = MAX_LEN;
    if (GetComputerName(szBuffer, & len)) {
        // TODO
    }
#else
    szBuffer = "";
#endif
    return szBuffer;
}
std::string getUserName() {
    const int MAX_LEN = 15; // Administrator min -> 15
    char szBuffer[MAX_LEN];
#if defined _WIN32 // windows system
    DWORD len = MAX_LEN;
    if (GetUserNameA(szBuffer, &len)){
        // TODO
    }
#else // outher system
    szBiffer = "";
#endif
    return szBuffer;
}
static void printTime() {
    time_t now = time (0);
    tm localtime;
    localtime_s(&localtime, &now);
    std::string time = "[CN:";
    int year = 1900 + localtime.tm_year;
    int month = 1 + localtime.tm_mon;
    int w_day = localtime.tm_wday;
    std::string weekday = "";
    switch (w_day) {
        case 1: weekday = "Mon"; break;
        case 2: weekday = "Feb"; break;
        case 3: weekday = "Wed"; break;
        case 4: weekday = "Thu"; break;
        case 5: weekday = "Fri"; break;
        case 6: weekday = "Sat"; break;
        case 7: weekday = "Sun"; break;
        default: break;
    }
    std::cout << time << weekday << "/"
        << year << "/" << month << "/" << localtime.tm_mday << "-"
        << localtime.tm_hour << ":" << localtime.tm_min << ":" << localtime.tm_sec << "]"
        << " => ";
    /*
    tm gmtm;
    gmtime_s(&gmtm, &now);
    std::cout << "UTC time: " ;
    std::cout << "year-" << gmtm.tm_year + 1900 << " month-" << gmtm.tm_mon + 1 << std::endl;
     */
}

static void printUserHost() {
    std::cout << getUserName() << "@" << getPcName() <<" => ";
}
static void printLabel() {
    printTime();
    printUserHost();
}
#endif //WEBREP_PY_OWNER_TIMER_H
