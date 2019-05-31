#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;
//差生随机大小的文件 单位是B
typedef long long ll;

int main ()
{
    int num;
    string goalPath;
    cout<<"please input the file number:"<<endl;
    cin>>num;
    cout<<"the files goal path?"<<"(the demo is:  C:/Users/lenovo/Desktop/test )"<<endl;
    //参考格式 goalPath = "C:/Users/lenovo/Desktop/test";
    cin>>goalPath;
    srand((unsigned)time(NULL));
    for(int i=0;i<num;i++)
    {
        string outPath = goalPath + "/" + to_string(i) + ".out";

        ll size=0;
        char tmp;
        string res;
        //随机数据生成
        size = rand() % 80000*1000 + 30000000;
        cout<<size<<endl;
        while(size--)
        {
            tmp = (char)(rand() % (126-32+1)+ 32);
            res += tmp;
        }
        //文件写入
        ofstream fout;
		fout.open(outPath,ios::app);
		if (!fout)
		{
			cout << "open file faild!" << endl;
			return 0;
		}
		fout << res;
		fout.close();
        cout<<outPath <<"  wirte success!"<<endl;
    }
       system("pause");
       return 0;
}
