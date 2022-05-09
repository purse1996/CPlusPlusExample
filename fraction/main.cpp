//
// Created by zhangshuaibin on 2022/5/9.
//
#include<iostream>
#include"fraction.h"
using namespace std;
int main(){
    Fraction a(1, 4);
    cout << (double)a << endl;
    // explicit保持4转换为double而非Fraction，避免歧义
    cout << a + 4;
    return 0;
}
