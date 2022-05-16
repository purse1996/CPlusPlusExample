//
// Created by zhangshuaibin on 2022/5/16.
//
#include<iostream>
// 算法
#include<algorithm>
// 仿函数
#include<functional>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<map>
#include<unordered_set>
using namespace std;
int main()
{
    /*第一类容器..............*/
    vector<int> a = {1, 4, 3, 7, 10};
    a.push_back(8);
    cout << "vector size " << a.size() << endl;
    // vector capactity是以接近2^n进行容量增大的
    cout << "vector capacity " << a.capacity() << endl;
    // greater<int>()仿函数，本质是个模板，()创建了一个临时对象
    sort(a.begin(), a.end(), greater<int>());
    for(int temp : a)
    {
        cout << temp << " " ;
    }
    auto target = find(a.begin(), a.end(), 4);
    if(target != a.end())
        cout << "find target postion " << distance(a.begin(), target) << endl;

    //list, foward_list 地址不连续，不存在[]
    list<int> a_list = {7, 5, 2, 1, 6, 8};
    // 列表中自带了sort函数
    a_list.sort(greater<int>());
    // 遍历
    for(list<int>::iterator temp=a_list.begin(); temp!=a_list.end(); temp++)
    {
        cout << *temp << " ";
    }
    for(auto temp : a_list)
        cout << temp << " ";
    cout << endl;

    // deque queue stack是基于list实现的
    // deque由若干个buffer指针组成，每次扩充一个buffer
    deque<int> a_deque = {7, 5, 2, 1, 6, 8};
    sort(a_deque.begin(), a_deque.end(), less<int>());
    for(auto temp : a_deque)
        cout << temp << " ";

    cout << endl;
    /*第二类容器，关联容器，适合查找，都含有自带的find函数*/
    // multiset multimap 都是基于二叉树实现的会默认按照key排序
    multiset<int> a_multiset = {3, 1, 3, 2, 5, 8, 7};
    a_multiset.insert(20);
    auto target_multiset = a_multiset.find(7);
    if(target_multiset != a_multiset.end())
        cout << "multiset find " << *target_multiset << endl;
    for(auto temp : a_multiset)
        cout << temp << " ";
    cout << endl;
    multimap<int, string> a_multimap = {make_pair(1, "wuhan"),
                                        make_pair(5, "beijing"),
                                        make_pair(3, "dongfang"),};
    for(auto temp : a_multimap)
        cout << temp.first << "  " << temp.second << endl;
    auto target_multimap = a_multimap.find(5);
    cout << "multimap find " << (*target_multimap).first << " " << (*target_multimap).second << endl;

    // 类似的是unordered_map和unordered_set
    // 基于hash表实现的，其中key没有排序，但查找速度更快(O(1))，multiset复杂度为(O(log(n)))
    // 但也没有重复元素
    unordered_set<int> a_unordered_set = {3, 1, 3, 2, 5, 8, 7};
    a_unordered_set.insert(20);
    cout << "..........unordered_set............" << endl;
    for(auto temp : a_unordered_set)
        cout << temp << " ";
    cout << endl;

    // 第二个相关的是set和map，基于红黑树实现的，已经排序了，这中间也没有重复元素!
    cout << "................set..............." << endl;
    set<int> a_set = {3, 1, 3, 2, 5, 8, 7};
    for(auto temp : a_set)
        cout << temp << " ";

    return 0;
}
