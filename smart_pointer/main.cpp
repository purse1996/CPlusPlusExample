//
// Created by zhangshuaibin on 2022/5/10.
//
#include<iostream>
#include"pointer.h"
#include<string>
#include<iostream>
using namespace std;
int main()
{
    StringBlob s1 = {"test1", "tess4", "test5"};
    s1.push_back("test");
    // unique_ptr<string> up = new string("wuhjandaxue"); wrong explicit不允许拷贝构造

    //unique_ptr独享对象，一些基本用法
    unique_ptr<string> up(new string("wuhand"));
    unique_ptr<string> up3(new string("beijing"));
    string* up_point = new string("11111");
    cout << "unique_ptr size " << sizeof(up) << endl;
    cout << *up << endl;
    unique_ptr<string> up2(up.release()); // 所有权转移
    cout << *up2 << endl;
    cout <<  *up3 << endl;
    up3.reset(up_point); // 所有权转移
    cout << *up3 << endl;
    up3.reset(nullptr);

    // weak_ptr共享指针的复制指针，可以避免共享指针的循环引用问题
    shared_ptr<WoMan> woman = make_shared<WoMan>();
    shared_ptr<Man> man = make_shared<Man>();
    woman->setdata(man);
    man->setdata(woman);
    cout << man.use_count() << endl; // 2
    cout << woman.use_count() << endl; // 1
    cout << "............" << endl;

    //weak_ptr基本用法
    auto p = make_shared<int>(3);
    weak_ptr<int> w_p(p);
    cout << "wark ptr size " << sizeof(w_p) << endl;
    //返回指向w智能指针，或者空
    auto p2 = w_p.lock();
    cout << p.use_count() << endl;
    weak_ptr<int> w_p2(p);
    p2.reset();
    p.reset();
    // 判断p.use_count是否为0
    if(w_p2.expired()){
        cout << "p has no object" << endl;
    }
    cout << p.use_count() << endl;
    return 0;
}
