#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,string> > v;

int main()
{
	int N;
	cin>>N;
	string name;
	int h = 0;
	for(int i = 0; i < N; i++)
	{
		cin>>name;
		cin>>h;
		v.push_back(make_pair(h,name));
	}
	sort(v.begin(),v.end());

	for(vector<pair<int,string> >::iterator it = v.begin(); it != v.end(); it++)
		cout<< it->second << " " << it->first << endl;
}