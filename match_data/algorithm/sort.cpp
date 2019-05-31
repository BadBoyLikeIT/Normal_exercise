#include <iostream>

using namespace std;
//交换排序
//冒泡 稳定 每一次都会有一个数字到最终的位置
void swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
void bubble(int a[],int num)
{
    for(int i=0;i<num-1;i++)
        for(int j=0;j<num-i-1;j++)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
}

//快排 不稳定 每次中间的数字会有序
//数据量中等时选用 数量太大可能会爆栈

int qivotPosition(int a[],int low,int high)
{
    int temp = a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=temp)high--;
        a[low] = a[high];
        while(low<high&&a[low]<=temp)low++;
        a[high] = a[low];
    }
    a[low] = temp;
    return low;
}

void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int qivot = qivotPosition(a,low,high);
        quickSort(a,low,qivot-1);
        quickSort(a,qivot+1,high);
    }
}

//插入排序
//直接插入 稳定 前面的一部分总是有序的
//数据量比较小的时候适用

void directInsert(int a[],int num)
{
    int temp;
    for(int i=0; i<num-1; i++)
    {
        if(a[i]>a[i+1])
        {
            int j;
            temp = a[i+1];
            for(j=i; temp<a[j]&&j>=0; j-- )
                a[j+1] = a[j];
            a[j+1] = temp;
        }
    }
}
//希尔排序 不稳定 跨步长有序
//步长的起始值为num/2

void shellSort(int a[],int num)
{
    int temp;
    for(int dk=num/2; dk>=1; dk/=2)
        for(int i=dk; i<=num; i++)
         {
            if(a[i]<a[i-dk])
            {
                temp = a[i];
                int j;
                for(j=i-dk;temp<a[j]&&j>=0;j-=dk)
                    a[j+dk] = a[j];
                a[j+dk] = temp;
            }
         }
}
//选择排序 不稳定
//简单选择排序 每次都能有一个有序
void selectSort(int a[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        int min = i;
        for(int j=i+1;j<num;j++)
            if(a[j]<a[min])min = j;  //记录最小值
        if(min!=i)
            swap(a[i],a[min]);
    }
}

//堆排  因为最后的交换 所以也是不稳定排序
//分为大顶堆和小顶堆 本例以大顶堆为例 每次调整之后都可以找到最大值
//本例中的数据有特殊性 a[1]-a[num] 其中a[0]为临时存储容器 所以数组声明需要a[num+1]
void adjustDown(int a[],int k,int num);
void buildMaxHeap(int a[],int num)
{
    for(int i=num/2;i>0;i--)
        adjustDown(a,i,num);
}
void adjustDown(int a[],int k,int num)
{
    a[0] = a[k];
    for(int i=2*k;i<=num;i*=2)
    {
        if(i<num&&a[i]<a[i+1])
            i++;
        if(a[0]>=a[i])break;
        else
        {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}
void heapSort(int a[],int num)
{
    buildMaxHeap(a,num);
    for(int i=num;i>1;i--)
    {
        swap(a[i],a[1]);
        adjustDown(a,1,i-1);
    }
}
//归并排序 稳定排序 局部有序，进而全局有序
int b[100];
void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    for(k=low;k<=high;k++)
    {
        b[k] = a[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
    {
        if(b[i]<=b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while(i<=mid) a[k++] = b[i++];               //若第一个表未检测完，复制
    while(j<=high) a[k++] = b[j++];              //若第二个表未检测完，复制
}
void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int num;
    int a[100];
    /*
    //堆排的输入输出
    while(cin>>num)
    {
        for(int i=1;i<=num;i++)
            cin>>a[i];
        heapSort(a,num);
        for(int i=1;i<=num;i++)
            cout<<a[i]<<" ";
        cout<<endl;

    }*/


    while(cin>>num)
    {
    //cin>>num;  //一个数组的长度
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    //bubble(a,num);
    //quickSort(a,0,num-1);
    //directInsert(a,num);
    //shellSort(a,num);
    //selectSort(a,num);
    mergeSort(a,0,num-1);
    for(int i=0;i<num;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    }


    return 0;
}
