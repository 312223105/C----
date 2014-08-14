#include <iostream>
#include <list>

using namespace std;

list<int> lst;

void print_normal()
{
	list<int>::iterator it = lst.begin();

	int count = 1;
	for(; it != lst.end(); it++,count++)
	{
		cout<<*it <<" ";
		if(count % 10 == 0)
			cout<<endl;
		
	}
	cout<<endl<<endl;
}

void print_reverse()
{
	list<int>::reverse_iterator it = lst.rbegin();

	int count = 1;
	for(; it != lst.rend(); it++,count++)
	{
		cout<< *it <<" ";
		if(count % 10 == 0)
			cout << endl;
	}

	cout<<endl<<endl;

}
//有问题
/*bool greater(const int &a,const int &b)
{
	return *a > *b ? 1 : 0;
}*/


int main()
{
	cout<<"list insert"<<endl;
	lst.push_back(1);
	lst.push_back(1);
	cout<<"list print_normal"<<endl;
	print_normal();

	cout<<"list insert(++lst.begin(),10)"<<endl;
	lst.insert(++lst.begin(),10);
	print_normal();

	cout<<"list reverse()"<<endl;
	lst.reverse();
	cout<<"print_normal"<<endl;
	print_normal();
	cout<<"print_reverse()"<<endl;
	print_reverse();
	cout<<endl;

	cout<<"list push_back(10)"<<endl;
	lst.push_back(10);
	print_normal();

	cout<<"list pop_back()"<<endl;
	lst.pop_back();
	print_normal();

	cout<<"list push_front(99)"<<endl;
	lst.push_front(99);
	print_normal();

	cout<<"list pop_front()"<<endl;
	lst.pop_front();
	print_normal();

	cout<<"list sort()"<<endl;
	lst.sort();
	print_normal();

	//有问题
	/*cout<<"list sort(greater)  定义比较函数"<<endl;
	lst.sort(greater);
	print_normal();*/

	cout<<"list unique()"<<endl;
	lst.unique();
	print_normal();
	return 0;
}
