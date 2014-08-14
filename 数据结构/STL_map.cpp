#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string,vector<int> > xz;

void print()
{
	for(map<string,vector<int> >::iterator it = xz.begin(); it != xz.end(); it++)
	{
		cout<<"map["<<it->first<<"]:";
		for(vector<int>::iterator itVct = it->second.begin(); itVct != it->second.end(); itVct++)
		{
			cout<< *itVct <<" ";
		}
		cout<<endl;
	}
		
}

int main()
{
	cout<<"map insert:"<<endl;
	vector<int> vct1(10,1);
	xz["apple"] = vct1;
	print();
	
	cout<<endl;
	if(xz.count("apple"))
	{
		cout<<"apple in map."<<endl;
	}

	cout<<"map erase:"<<endl;
	xz.erase("apple");
	print();
	cout<<endl;
	if(xz.count("apple"))
	{
		cout<<"apple in map."<<endl;
	}
	else
		cout<<"apple not in map."<<endl;

	return 0;
}
