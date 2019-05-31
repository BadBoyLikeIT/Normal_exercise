#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector <int> vec;
    //插入
    for(int i=0; i<10;i++)
        vec.push_back(i);
    //删除
    vec.pop_back();
    //查询
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;
    cout<<vec[1]<<endl;
    //遍历查询
    for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
        cout<<*it<<endl;
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;
    vec.clear(); //释放了指针
}
