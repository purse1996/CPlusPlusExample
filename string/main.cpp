//
// Created by zhangshuaibin on 2022/5/9.
//
#include<iostream>
#include"myString.h"
using namespace std;
int main()
{
    myString a("defg");
    myString b;
    b = a; //调用的赋值函数
    myString c = a; // 调用的拷贝构造函数
    cout << a << "  " << b << "  " << c << "  " << endl;

    return 0;
}

