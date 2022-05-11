//
// Created by zhangshuaibin on 2022/5/11.
//

#ifndef BOOK_QUOTE_H
#define BOOK_QUOTE_H
#include<iostream>
using namespace std;
class Quote{
public:
    Quote(double _price) : price(_price) {}
    virtual const double& sell_price() const {
        return price;
    }
    // 基类往往需要构造一个虚析构函数
    virtual ~Quote(){
        cout << "Quote has destroy" << endl;
    }

protected:
    double price;
};

class Bulk_Quote : public Quote {
public:
    Bulk_Quote(double _ratio, double _price) : Quote(_price), ratio(_ratio) {}
    // override强制表示是继承虚函数
    const double& sell_price() const override{
        return ratio * price;
    }
    ~Bulk_Quote(){
        cout << "Bulk_Quoto has destroy" << endl;
    }
private:
    double ratio;

};

#endif //BOOK_QUOTE_H
