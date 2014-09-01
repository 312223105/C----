#include <iostream>

using namespace std;

int mi(int num, n)
{
	if(n == 0)
		return 1;

	int ans = 1;
	for(int i = 0; i < n; i++)
		ans *= num;

	return ans;
}



int main()
{
	int n, d;
	while(cin>>n)
	{
		if(n < 0)	break;

		cin>>d;
		int num = 0;
		int count = 0;
		while(n > 10)
		{
			num += n % d * mi(d, count);
			count++;
		}
	}
}