//
// Created by zhangshuaibin on 2022/5/9.
//

#ifndef FUNCTOR_BIGGER_H
#define FUNCTOR_BIGGER_H
class BiggerThan{
public:
    // 仿函数定义
    BiggerThan(double _threshold=0) : threshold(_threshold) {}
    bool operator() (const double& i) const{
        return i > threshold;
    }

private:
    double threshold;
};
#endif //FUNCTOR_BIGGER_H
