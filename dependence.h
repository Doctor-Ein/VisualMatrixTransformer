#ifndef _dependence_h
#define _dependence_h

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

int cnt = 0; // 全局的计数器

// 单个日志文件结构体
struct LogFile
{
    int id;         // 唯一标志某条日志信息
    int type;       // 标志日志信息类型，0为Normal，1为Error
    string message; // 信息主体
    LogFile():id(0), type(0), message("") {};
    LogFile(int id, int type, string message) : id(id), type(type), message(message) {};
};

#endif