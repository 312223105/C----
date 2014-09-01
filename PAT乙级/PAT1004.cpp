#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	vector<pair<int, pair<string, string> > >data;

	string name, id;
	int score;

	int N;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>name >>id >>score;
		data.push_back(make_pair(score, make_pair(name, id)));
	}

	sort(data.begin(), data.end());

	cout<<data[data.size() - 1].second.first<<" "<<data[data.size() - 1].second.second<<endl;
	cout<<data[0].second.first<<" "<<data[0].second.second<<endl;

	return 0;
}