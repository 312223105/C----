#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

vector<double> data;
int N;
int main()
{
	cin>>N;
	double temp,result = 0;
	for(int i = 0 ;i < N; i++)
	{
		cin>>temp;
		result += temp;
		data.push_back(temp);
	}

	double avg = result / N;
	double ans = 0.0;
	for(vector<double>::iterator it = data.begin(); it != data.end() ; it++)
	{
		double t = pow((double)(*it - avg),2);
		ans += t;
	}

	ans /= N;
	ans = sqrt(ans);

	printf("%.05f",ans);


}