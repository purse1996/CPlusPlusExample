//
// Created by zhangshuaibin on 2022/5/11.
//
#include<iostream>
#include<vector>
using namespace std;
void print()
{

}
// 1. 可变参数
template<typename T, typename... Types>
void print(const T& first, const Types&... args)
{
    cout << first << endl;
    print(args...);
}

int  main()
{
    print("wuhan", "beijing", 2333333);
    vector<int> test = {1, 50, 3, 5, 4};
    // vector<int>::iterator position = find(test.begin(), test.end(), 50);
    // 2. auto可以替代上面参数
    auto position =find(test.begin(), test.end(), 50);
    if(position != test.end()){
        cout << *position << endl;
        cout << "position " << distance(test.begin(), position) << endl;
    }
    // 3. ranged-base
    // 值访问
    for(auto i : test){
        cout << i << " ";
    }
    cout << endl;
    // 引用访问
    for(auto &i : test){
        i = 10;
    }
    for(auto i : test){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
