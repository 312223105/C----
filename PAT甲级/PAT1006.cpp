#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<pair<string, string> > begins;
	set<pair<string, string> > ends;

	int N;
	cin>>N;
	string a,b,c;
	for(int i = 0; i < N; i++)
	{
		cin>>a>>b>>c;
		begins.insert(make_pair(b,a));
		ends.insert(make_pair(c,a));
	}


	set<pair<string, string> >::iterator it = ends.begin();
	for(int i = 1; i < ends.size(); i++)
	{
		it++;
	}

	cout<<begins.begin()->second<<" "<<it->second<<endl;
	return 0;
}