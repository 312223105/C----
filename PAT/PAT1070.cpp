//题目中给出的库存吨数不只是整数
//须把库存和剩余需求都定义为double才行

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cake
{
	double price;
	double danjia;
	double tons;
}mooncakes[1005];

bool cmp(const cake &a,const cake &b)
{
	return a.danjia > b.danjia ? true : false;
}

int main()
{
	int N,D;
	cin>>N>>D;
	double _price;
	double _tons;
	for(int i = 0; i < N; i++)
	{
		cin>>_tons;
		mooncakes[i].tons = _tons;
	}

	for(int i = 0; i < N; i++)
	{
		cin>>_price;
		mooncakes[i].price = _price;
		mooncakes[i].danjia = _price / mooncakes[i].tons;
	}

	sort(mooncakes,mooncakes + N, cmp);

	double rest = D;

	int i = 0;
	double ans = 0;
	while(rest >= mooncakes[i].tons && i < N)
	{
		ans += mooncakes[i].price;
		rest -= mooncakes[i].tons;
		i++;
	}

	if(rest != 0 && i != N)
	{
		ans += mooncakes[i].danjia * rest;
	}

	printf("%.2f\n",ans);
}
