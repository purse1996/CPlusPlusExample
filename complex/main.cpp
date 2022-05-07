
//
// Created by zhangshuaibin on 2022/5/7.
//
#include<iostream>
#include<complex.h>
using namespace std;
int main()
{
    Complex<double> a;
    a.setRe(2.0);
    a.setImag(3.0);
    cout << a << endl;
    Complex<double> b(1.5, 2.0);
    a = a + 3;
    cout << a << endl;
    Complex<double> c = a + b;
    cout << c << endl;
    Complex<double> d = b + 3;
    cout << d << endl;
    cout << c<< endl << d;
    return 0;
}
