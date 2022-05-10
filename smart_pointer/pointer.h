//
// Created by zhangshuaibin on 2022/5/10.
//

#ifndef SMART_POINTER_POINTER_H
#define SMART_POINTER_POINTER_H
#include<memory>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class StringBlob{
public:
    StringBlob()  {}
    StringBlob(initializer_list<string> ss) : sp(make_shared<vector<string>>(ss)) {}
    void push_back(const string& s) {
        sp->push_back(s);
    }
    void pop_back(){
        if(check(0))
            sp->pop_back();
    }

private:
    shared_ptr<vector<string> > sp;
    bool check(const int& i){
        if(i>0 && i<sp->size())
            return true;
        else
            return false;
    }

};
class WoMan;
class Man{
public:
    //注意使用智能指针进行值传递时的内存泄露问题
    void setdata(shared_ptr<WoMan> _mdata){
        mdata = _mdata;
    }
    // 注意程序结束时析构函数是否会被调用，来判断是否存在内存泄漏问题
    ~Man(){
        std::cout << "Man has destory" << std::endl;
    }
private:
//    shared_ptr<WoMan> mdata;
    weak_ptr<WoMan> mdata;
};

class WoMan{
public:
    void setdata(shared_ptr<Man> _mdata){
//        std::cout << _mdata.use_count() << "......." << endl;
        mdata = _mdata;
//        std::cout << _mdata.use_count() << "......." << endl;
    }
    ~WoMan(){
        std::cout << "woman has destory" << std::endl;
    };
private:
    shared_ptr<Man> mdata;
};
#endif //SMART_POINTER_POINTER_H
