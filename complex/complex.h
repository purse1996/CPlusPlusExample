//
// Created by zhangshuaibin on 2022/5/7.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H
#include<ostream>
using namespace std;
template<typename T>
class Complex{
public:
    Complex() : re(0), imag(0){
    }
    // 为什么构造函数不能传引用？
    Complex(T _re, T _imag) : re(_re), imag(_imag){
    }
    //传引用，但存在修改，不能用const
    void setRe(const T& _re){
        re = _re;
    }
    void setImag(const T& _imag){
        imag = _imag;
    }
    //不能返回引用，返回引用代表可能修改，与const矛盾
    T getRe() const{
      return re;
    }
    T getImag() const{
        return imag;
    }
    //调用类，必须要加上模板参数
    Complex<T>& operator+ (const T& _re);

    // 函数内部使用友元函数模板，必须加上typename
    template<typename N>
    friend Complex<N> operator+ (const Complex<N>& a, const Complex<N>& b);
    template<typename N>
    friend Complex<N> operator+ (const N& _re, const Complex<N>& a);
private:
    T re;
    T imag;
};

template<typename T>
inline Complex<T> operator+ (const Complex<T>& a, const Complex<T>& b)
{
    Complex<T> com_sum = Complex<T>(a.re+b.re, a.imag+b.imag);
    return com_sum;
}

template<typename T>
inline Complex<T> operator+ (const T& _re, const Complex<T>& a)
{
    Complex<T> com_sum = Complex<T>(a.re+_re, a.image);
    return com_sum;
}

template<typename T>
inline Complex<T>& Complex<T>::operator+ (const T& _re)
{
    this->re = this->re + _re;
    return *this;
}

// 重载的是ostream，必须有返回值，满足连续打印的情况。
template<typename T>
inline ostream& operator << (ostream& os, const Complex<T>& a)
{
    return os << a.getRe() << ".........." << a.getImag();
}


#endif //COMPLEX_COMPLEX_H
