/*
 * init.hpp
 * 初始化头文件、结构体声明、常量定义
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>
#include <condition_variable>
#include <functional>
using namespace std;
#pragma GCC std("c++11")
const string _VERSION_ = "a0.0.1";
const int _BUFFER_SIZE_ = 1024;

vector<string> split(string str) {
    vector<string> result;
    size_t index = str.find(' ');
    if (index == string::npos) {
        result.push_back(str);
        return result;
    }
    result.push_back(str.substr(0, index));
    result.push_back(str.substr(index + 1));
    return result;
}

struct ifStr {
    bool flag;
};
struct loopStr {
    bool flag;
    string var;
    streampos line;
};

stack<ifStr> ifSta;
stack<loopStr> loopSta;
char buffer[_BUFFER_SIZE_];
map <string, void (*)(vector<string>::iterator, ifstream &)> identifiers;
map <string, long double> variables;
