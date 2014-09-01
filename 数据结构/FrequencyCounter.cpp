#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string,int> words;
	string str;
	while(cin>>str)
	{
		if(str.size() < 8)
			continue;
		words[str]++;
	}

	map<string,int>::iterator it = words.begin();
	map<string,int>::iterator ans = words.begin();
	for(; it != words.end(); it++)
	{
		if(ans->second < it->second)
			ans = it;
	}

	cout<<ans->first<<"  "<<ans->second<<endl;
}