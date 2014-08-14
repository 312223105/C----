//大整数乘法
#include<iostream>
#include<string>
using namespace std;

void MUL_max(string a,int la,string b,int lb,int **c);//相乘函数
void ADD_max(int * d,int **c,int la,int lb);//相加函数
char * ZhuanH(string);

int main()
{
	string a;
	string b;
	cout<<"         *******************大整数乘法********************"<<endl;
	cout<<"             (当乘数和被乘数输入值都为0时，程序结束!)"<<endl;
	cout<<"请输入乘数：";
	cin>>a;
	cout<<"请输入被乘数：";
	cin>>b;
    while(a!="0"||b!="0")
	{
	int **c=NULL;

	int *d=NULL;
	int la=0,lb=0;
	int i=0,j=0,k=0;
	la=a.length();
	lb=b.length();

	//分配2维C数组，存储数组a和b的乘积
	c=new int*[la];
 	for(k=0;k<la;k++)
		c[k]=new int[lb+1];
	//分配数组d用于存储最终结果
	d=new int[la+lb+1];
	for(i=0;i<la+lb+1;i++)//初始化，便于后面判断相加后的有效位数
		d[i]=0;

	//初始化数组C，便于后面判断相加后的有效位数
	for(i=0;i<la;i++)
		for(j=0;j<=lb;j++)
			c[i][j]=0;

	//调用函数
	MUL_max(a,la,b,lb,c);
	ADD_max(d,c,la,lb);
	
	k=0;
	cout<<"相乘结果是："<<endl;
	for(i=0;i<=la+lb;i++)
	{	
		if(d[i]==0)
			k++;
		else
			break;
	}
	if(k>la+lb)
		cout<<0;
	else
	    for(i=k;i<=la+lb;i++)
		   cout<<d[i];
	cout<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"请输入乘数：";
	cin>>a;
	cout<<"请输入被乘数：";
	cin>>b;
	}

	return 0;
}


void MUL_max(string a,int la,string b,int lb,int **c)
{
	int mid=0,i=0,j=0;
	int k=0;
	int num_a=0,num_b=0;

	//开始循环相乘la*lb次
	for(i=la-1;i>=0;i--)
	{
		for(j=lb-1;j>=0;j--)
		{
			num_a=a[i]-48;
		    num_b=b[j]-48;//字符转换

			if((k=num_a*num_b)>=10)//判断乘积是否有进位
			{
				if(mid!=0)//判断前一次相乘是否有进位
					c[i][j+1]=k%10+mid;//取余
				else
					c[i][j+1]=k%10;
				
				mid=k/10;//取整

			}
			else//没有进位
			{
				if(mid!=0)//判断前一次相乘是否有进位
					c[i][j+1]=k+mid;//取余
				else
					c[i][j+1]=k;
				
				mid=0;
			}

		}
		if(mid!=0)
			c[i][0]=k/10;//如果乘数个位和被乘数相乘，最后有进位
	}
}

//数组相加函数
void ADD_max(int *d,int **c,int la,int lb)
{
	int i=0,j=0;
	int mid=0;
	int num_a=0,num_b=0;
	int add=0,midnum=0;

	//将相乘得到的二维数组C各行错位相加，得到一位数组d
	for(i=la-1;i>=0;i--)
		for(j=lb;j>=0;j--)
		{
			num_a=d[i+j+1];
			num_b=c[i][j];
			add=num_a+num_b;

			if(add>=10)//判断相加是否有进位
			{
				if(midnum==1)
					d[i+j+1]=add%10+1;
				else
					d[i+j+1]=add%10;
				midnum=1;
			}
			else
			{
				d[i+j+1]=add;
				midnum=0;
			}
		}
	if(midnum==1)
		d[0]=add/10;
}
