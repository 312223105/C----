//测试点3 运行超时，有待优化！！

#include <iostream>
#include <set>
#include <map>
#include <cmath>

using namespace std;

/*set<long> primes;
set<long> no_primes;*/
bool is_prime(int n)
{
	if(n == 1 || n == 2)
		return true;

/*	if(no_primes.find(n) == no_primes.end())
	{
		return false;
	}

	if(primes.find(n) == primes.end())
	{
		return true;
	}	*/
		
	
	bool flag = true;
	int sq = (int)sqrt(n);
	for(int i = 2 ; i <= sq; i++)
		if(n % i == 0)
		{
			flag = false;
			break;
		}

/*	if(flag)
		primes.insert(n);
	else
		no_primes.insert(n);*/
	return flag;
}

int main()
{
	int num;
	cin>>num;

	map<int,int> a_map;

	int temp = num;
	int chushu = 2;
	int beichushu;
	while(temp >= chushu)
	{
		if(is_prime(chushu))
		{
			while(temp % chushu == 0)
			{
				temp = temp / chushu;
				a_map[chushu]++;
			}
		}
		chushu++;
	}


	cout<<num<<"=";
	map<int,int>::iterator first,it,end;
	first = a_map.begin();
	end = a_map.end();

	cout<<first->first;

	if(first->second != 1)
	{
		cout<<"^"<<first->second;
	}
	first++;
	for(it = first; it != end; it++)
	{
		cout<<"*"<<it->first;
		if(it->second != 1)
		{
			cout<<"^"<<it->second;
		}
	}


	return 0;
}
