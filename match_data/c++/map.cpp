#include <iostream>
#include <map>
using namespace std;

int main()
{
    //声明
    map<int,string> lsmap;
    //插入
    lsmap.insert(map<int,string>::value_type(1,"lishuai"));
    lsmap[2] = "wangwenjing";
    lsmap.insert(pair<int,string>(3,"shenzimo"));
    //删除
    lsmap.erase(3);
    //遍历 查询
    for(map<int,string>::iterator it = lsmap.begin();it != lsmap.end(); it++)
    {
        cout<<it->second<<endl;
    }
    //单项查询
    map<int,string>::iterator it1 = lsmap.find(2);
    if(it1!=lsmap.end())
        cout<<"find "<<lsmap[2]<<endl;
    vec.clear(); //释放了指针
}
