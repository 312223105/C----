#include <iostream>

using namespace std;


int id[1000];
int sz[1000];
int count = 0;

int find(int p)
{
	int proot = p;
	while(proot != id[p])
		proot = id[p];
	return proot;
}

void union_(int p,int q)
{
	int proot = find(p);
	int qroot = find(q);

	if(proot == qroot)
		return;

	if(sz[proot] > sz[qroot])
	{
		id[qroot] = proot;
		sz[proot] += sz[qroot];
	}
	else
	{
		id[proot] = qroot;
		sz[qroot] += sz[proot];
	}

	::count--;
}

void init_(int n)
{
	::count = n;
	for(int i = 0 ;i < n; i++)
	{
		sz[i] = 1;
		id[i] = i;
	}

}
int main()
{
	init_(100);

	int p,q;
	while(cin>>p>>q)
	{
		cout<<p<<q;
		union_(p,q);
	}

	cout<<"count = "<<::count<<endl;

	return 0;
}