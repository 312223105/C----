#include <iostream>

using namespace std;
#define N 1010

int lesson[N][2];   //记录开课时间 与 下课时间
int num[N]; // 记录上第N堂课的话可上的最大课程

int main()
{
    int n;
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>lesson[i][0]>>lesson[i][1];    //输入开课时间与课程结束时间
    memset(num,0,sizeof(num));
    num[n] = 1; //第一阶段，首先上最后一堂课的话，最大上课数为 1
    int max1;
    for(i=n-1;i>=1;i--) //从后往前遍历
    {
        max1 = 0;
        for( j = i+1;j<=n;j++)  //遍历从 i+1 堂课 到最后一场课<span style="white-space:pre">	</span>(动态规划，求解局部最优)
        {
            if(lesson[i][1] <= lesson[j][0] &&  max1 <num[j])    //比较i场课的结束课的时间 与 第j场课(j>i)的开始时间
                max1 = num[j];
        }
        //已经找到了 上过第i场课之后 还能上的课的最大值
        num[i] = max1+1 ;
    }

    for(max1=0,i=1;i<=n;i++)
        if(max1 < num[i])
            max1 = num[i];
    cout<<max1<<endl;
    return 0;
}
