//
// Created by zhangshuaibin on 2022/5/9.
//

#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H
#include<ostream>
#include<string>
using namespace std;

class myString {
public:
    myString(const char* _str = nullptr){
        if(_str == nullptr)
        {
            str = new char[1];
            *str = '\0';
        }
        else{
            str = new char[strlen(_str) + 1];
            //strcpy会拷贝'\0
            strcpy(str, _str);
        }
    }
    // 拷贝构造函数必须使用引用，否则会无限循环
    myString(const myString& _str){
        str = new char[strlen(_str.str) + 1];
        strcpy(str, _str.str);
    }
    myString& operator= (const myString& _str){
        if(str == _str.str)
            return *this;
        else{
            delete []str;
            str = new char[strlen(_str.str) + 1];
            strcpy(str, _str.str);
            return *this;
        }
    }
    // 必须要有析构
    ~myString(){
        delete []str;
    }
    friend ostream& operator << (ostream& os, myString& str);
private:
    char* str;
};

// 友元函数类外实现
ostream& operator << (ostream& os, myString& str){
    return os << str.str;
}

#endif //STRING_MYSTRING_H
