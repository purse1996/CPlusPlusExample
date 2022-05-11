//
// Created by zhangshuaibin on 2022/5/11.
//
#include<iostream>
#include"quote.h"
#include<memory>
using namespace std;
int main()
{

    unique_ptr<Quote> q1(new Quote(10));
    unique_ptr<Quote> q2(new Bulk_Quote(0.5, 10));
    // 多态条件：1）指针/引用 2）派生类到基类 3) 虚函数
    cout << q1->sell_price() << endl;
    cout << q2->sell_price() << endl;
    // 强制访问基类函数
    cout << q2->Quote::sell_price() << endl;

    return 0;
}

