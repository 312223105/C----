#include <iostream>
#include <set>

using namespace std;

set<int> xz;

int main()
{
	int N,M;
	int temp;
	cin>>N>>M;
	for(int i = 0 ;i < N; i++)
	{
		cin>>temp;
		xz.insert(temp);
	}
	set<int>::iterator it;
	for(int i = 0; i < M; i++)
	{
		cin>>temp;
		it = xz.lower_bound(temp);
		if(it != xz.end())
			cout<<*it<<endl;
		else
			cout<<"Not found!"<<endl;
	}

	return 0;
}
