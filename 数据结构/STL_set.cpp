#include <iostream>
#include <set>

using namespace std;

set<int> xz;

void print()
{
	for(set<int>::iterator it = xz.begin(); it != xz.end(); it++)
		cout<<*it<<" ";
	cout<<endl<<endl;
}

int main()
{
	xz.insert(5);
	xz.insert(4);
	xz.insert(20);
	xz.insert(1);
	cout<<"set  insert: 5, 4, 20, 1"<<endl;
	print();


	xz.insert(20);
	cout<<"set insert 20 again"<<endl;
	print();

	cout<<"set erase 20 return -> "<<xz.erase(20)<<endl;
	print();

	cout<<"set erase  3 return -> "<<xz.erase(3)<<endl;
	print();

	// xz.insert(10); 
	//lower_bound : get equal or greater number
	if(xz.lower_bound(9) != xz.end())
		cout<<"set lower_bound(6) " <<*(xz.lower_bound(9))<<endl<<endl;
	else
		cout<<"set lower_bound(9) " <<"with null"<<endl<<endl;

	if(xz.upper_bound(-1) != xz.begin())
		cout<<"set upper_bound(-1) " <<*(xz.upper_bound(-1)) <<endl<<endl;
	else
		cout<<"set upper_bound(-1) " <<"with null"<<endl<<endl;

	if(xz.find(5) != xz.end())
		cout<<"set find(5) return the iterator which pointing to the found key." <<endl<<endl;
	else
		cout<<"set find(5) returned 'set.end',because not find the given key."<<endl<<endl;

	cout<<"set.count(_key) return '1' or '0'."<<endl<<endl;
	return 0;
}
