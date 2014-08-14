#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> xz;
int main()
{
	int N;
	cin >> N;
	char flag;
	string booknm;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> flag >> booknm;
		if (flag == '+')
		{
			cin >> num;
			xz[booknm] += num;
		}
		else if (flag == '-')
		{
			cin >> num;
			xz[booknm] -= num;
		}
		else if (flag = '?')
		{
			cout << xz[booknm] << endl;
		}
	}
	return 0;
}
