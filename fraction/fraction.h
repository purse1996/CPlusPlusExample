//
// Created by zhangshuaibin on 2022/5/9.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H
class Fraction{
public:
    explicit Fraction(int _numerator=0, int _denominator=0) : numerator(_numerator), denominator(_denominator) {}

    // 强制类型转换
    operator double() const{
        return (double)numerator / denominator;
    }
    Fraction& operator + (const Fraction& a)
    {
        numerator = numerator*a.denominator + denominator+a.numerator;
        denominator = denominator * a.denominator;
        return *this;
    }

private:
    int numerator;
    int denominator;

};
#endif //FRACTION_FRACTION_H
