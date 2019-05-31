#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main()
{
   set<int> set1;
   //增加
   for(int i=0;i<10;i++)
     set1.insert(i);
   //删除
    set1.erase(4);
   //查询
    if(set1.size()!=0)
    {
        set<int>::iterator it = set1.find(8);
        if(it!=set1.end())
            cout<<"find 8"<<endl;
    }
    //循环遍历
    for(set<int>::iterator it = set1.begin();it!=set1.end();it++)
        cout<<*it<<"\t";


}
