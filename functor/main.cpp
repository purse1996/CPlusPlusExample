//
// Created by zhangshuaibin on 2022/5/9.
//
#include<iostream>
#include"bigger.h"
using namespace std;
// 仿函数
int biggerNumber(double* array, int asize, const BiggerThan& bigger){
    int number = 0;
    for(int i=0; i < asize; i++)
    {
        number = bigger(array[i]) ? number+1 : number;
    }
    return number;
}

// 函数指针
int biggerNumberPoint(double* array, int asize, double threshold, bool (*fp)(double, double) ){
    int number = 0;
    for(int i=0; i < asize; i++)
    {
        number = fp(array[i], threshold) ? number+1 : number;
    }
    return number;
}

bool biggerPoint(double i, double threshold)
{
    return i > threshold;
}

int main()
{
    BiggerThan bigger(10);
    double array[] = {1.4, 12.0, 14.0, 15.0, 3.0};
    cout << biggerNumber(array, 5, bigger) << endl;
    cout << biggerNumberPoint(array, 5, 10, biggerPoint) << endl;
    return 0;
};
