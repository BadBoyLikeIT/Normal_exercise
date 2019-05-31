#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main ()
{
    FILE *f1,*f2;
    if((f1=fopen("out1.out","rb+"))==NULL)  { cout<<-1<<endl; return -1; }
    if((f2=fopen("out2.out","rb+"))==NULL)  { cout<<-2<<endl; return -2; }

    srand((unsigned)time(NULL));
    cout<<time(NULL)<<endl;
    ll n,tmp,diff,r_diff=0; double rato; char ch[2];
    memset(ch,0,sizeof(ch));
    cout<<"Enter block nums and ratoi:"; cin>>n>>rato;
    tmp = n;
    diff = (ll)n*rato; cout<<"Diff_block:"<<diff<<endl;
    int r=0;
    while(tmp--)
    {
        ch[0] = (char)(rand() % (126-32+1)+ 32);
        fwrite(ch,sizeof(char),1,f1);

        if(r_diff<diff)
        {
            r = rand()%100;
            if(r>=(int)100*rato) ;
            else
            {
                r_diff++;
                while( 1)
                {
                    char mm = (char)(rand() % (126-32+1)+ 32);
                    if(ch[0]!=mm) { ch[0]=mm; break; }
                }
            }
        }
        fwrite(ch,sizeof(char),1,f2);
    }
    fclose(f1);
    fclose(f2);
    cout<<"Actual Diff :"<<r_diff<<"Ratio:"<<(double)r_diff*1.0/n<<endl;
    return 0;
}
