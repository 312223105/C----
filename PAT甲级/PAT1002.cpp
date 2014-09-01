#include <iostream>
#include <map>
#include <vector>
using namespace std;

double pol1[1001], pol2[1001],ans[1001];
int main()
{
	int K;
	cin>>K;
	for(int i = 0 ; i < K; i++)
	{
		int ex;
		double co;
		cin>>ex>>co;
		pol1[ex] = co;
	}

	cin>>K;
	for(int i = 0 ; i < K; i++)
	{
		int ex;
		double co;
		cin>>ex>>co;
		pol2[ex] = co;
	}
	int count = 0;
	for(int i = 0 ; i < 1001; i++)
	{
		ans[i] = pol1[i] + pol2[i];
		if(ans[i] != 0.0)
			count++;
	}
	printf("%d",count);

	for(int i = 1000; i >=0; i--)
	{
		if(ans[i] != 0.0)
			printf(" %d %.1f", i, ans[i]);
	}
}
/*
//方法二
//map and vector 实现

map<int,double> a, b;
vector<pair<int,double> > ans;
int K;
int main()
{
	cin>>K;
	for(int i = 0 ; i < K; i++)
	{
		int x;
		double num;
		cin>>x>>num;
		a[x] = num;
		//printf("x = %d, num = %f\n", x, num);
	}
	cin>>K;
	for(int i = 0 ; i < K; i++)
	{
		int x;
		double num;
		cin>>x>>num;
		b[x] = num;
		//printf("x = %d, num = %f\n", x, num);
	}

	for(int i = 0 ; i <= 1000; i++)
	{
		double num1 = 0, num2 = 0;
		int flag = false;
		if(a.count(i) == 1)
		{
			flag = true;
			num1 = a[i];
		}

		if(b.count(i) == 1)
		{
			flag = true;
			num2 = b[i];
		}
		if(flag == true)
		{
			ans.push_back(make_pair(i, num1 + num2));

			//printf("a[%d] = %f, b[%d] = %f, ans[%d] = %f \n", i, num1, i, num2, i, num1+num2);
		}

	}

	int count = 0;
	vector<pair<int, double> >::reverse_iterator rit = ans.rbegin();
	for(; rit!= ans.rend(); rit++)
	{
		if(rit->second != 0.0)
			count++;
	}
	cout<<count;
	rit = ans.rbegin();
	for(; rit!= ans.rend(); rit++)
	{
		if(rit->second != 0.0)
			printf(" %d %.1f", rit->first, rit->second);

	}

}*/