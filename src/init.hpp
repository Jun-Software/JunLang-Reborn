/*
 * init.hpp
 * 初始化头文件、结构体声明、常量定义
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>
#include <condition_variable>
#include <functional>
#include <string>
#include <cctype>
#ifdef _WIN32
#define libload true
#include <windows.h>
#elif __linux__
#include <dlfcn.h>
#define libload true
#else
#define libload false
#endif
using namespace std;
#pragma GCC std("c++11")
const string _VERSION_ = "v1.0.0";
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

string cleanString(const string& input) {
    if (input.empty()) return "";
    
    const int len = static_cast<int>(input.length());
    string result;
    result.reserve(len);
    
    int i = 0;
    while (i < len && isspace(static_cast<unsigned char>(input[i]))) {
        ++i;
    }
    
    bool lastWasSpace = false;
    
    for (; i < len; ++i) {
        const char ch = input[i];
        
        if (ch == '#') {
            break;
        }
        
        if (isspace(static_cast<unsigned char>(ch))) {
            if (!lastWasSpace) {
                result += ' ';
                lastWasSpace = true;
            }
        } else {
            result += static_cast<char>(tolower(static_cast<unsigned char>(ch)));
            lastWasSpace = false;
        }
    }

    int end_pos = static_cast<int>(result.length()) - 1;
    while (end_pos >= 0 && isspace(static_cast<unsigned char>(result[end_pos]))) {
        --end_pos;
    }
    
    if (end_pos < 0) {
        return "";
    }
    
    return result.substr(0, end_pos + 1);
}

struct uStr {
    int line;
    string name;
};

stack<uStr> loopSta;
stack<uStr> funcSta;
char buffer[_BUFFER_SIZE_];
unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> > &, int &)> identifiers;
unordered_map <string, long double> variables;
unordered_map <string, int> funcs;

long double convert(string str) {
    if (isdigit(str[0])) {
        return stold(str);
    }
    else {
        return variables[str];
    }
}

long double eval(string str, int &line) {
    if (str[0] == '~') {
        return convert(str.substr(1));
    }
    vector<string> splited;
    long double res;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, ' ')) {
        if (!buffer.empty()) {
            splited.push_back(buffer);
        }
    } // 将传入字符串沿空格分割为多部分
    // 遍历分割后的多部分
    if (splited[0] == "not") {
        res = !(bool)(convert(splited[1]));
        return res;
    }
    res = convert(splited[0]);
    // 为什么string没有switch!!!!
    for (vector<string>::iterator it = splited.begin() + 1; it != splited.end(); ++it) {
        if ((*it) == "add") {
            res += convert(*(it+1));
        }
        else if ((*it) == "sub") {
            res -= convert(*(it+1));
        }
        else if ((*it) == "mlp") {
            res *= convert(*(it+1));
        }
        else if ((*it) == "div") {
            res /= convert(*(it+1));
        }
        else if ((*it) == "eq") {
            res = (res == convert(*(it+1)));
        }
        else if ((*it) == "ne") {
            res = (res != convert(*(it+1)));
        }
        else if ((*it) == "gt") {
            res = (res > convert(*(it+1)));
        }
        else if ((*it) == "ge") {
            res = (res >= convert(*(it+1)));
        }
        else if ((*it) == "lt") {
            res = (res < convert(*(it+1)));
        }
        else if ((*it) == "le") {
            res = (res <= convert(*(it+1)));
        }
        else {
            cerr << "[Error, " << line << "] Unknown EVAL identifier: " << (*it) << endl;
            exit(0);
        }
        it++;
    }
    return res;
}