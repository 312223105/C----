#include <iostream>
#include <time.h>

using namespace std;

//程序运行时间测试
/*
#define cycle 300

int main()
{
	clock_t start,finish;
   	double totaltime;
   	start=clock();
   	unsigned n = 0;
   	n--; 
   	unsigned test = 0;
	for(unsigned i = 0; i < cycle ; i++)
		for(unsigned j = 0; j < cycle; j++)
			for(unsigned k = 0; k < cycle; k++)
				test++;	
	cout<<test <<endl;

	finish=clock();
   	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   	cout<<"\neee"<<totaltime<<"  s!"<<endl;

}
*/
typedef long long LL;
int main()
{
	LL a;
	cin>>a;
	cout<<a;

	return 0;
}
