#include <iostream>
#include <vector>

using namespace std;
vector<int> vct(100, 1);

void print_normal()
{
	vector<int>::iterator it = vct.begin();

	for(; it != vct.end(); it++)
		cout<<*it<<" ";
	cout<<endl<<endl;
}

void print_reverse()
{
	vector<int>::reverse_iterator rit = vct.rbegin();

	for(; rit != vct.rend(); rit++)
		cout<<*rit <<" ";
	cout<<endl<<endl;
}

int main()
{

	int i = 0;
	for(vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
	{
		*it += (i++);
	}

	print_reverse();

	vct.push_back(20);
	vct.pop_back();
	cout<< vct.size()<<endl<<endl;

	cout<<"erase: vct.begin()"<<endl;
	vct.erase(vct.begin());
	print_normal();
	
	cout<<"erase :vct.begin() + 5"<<endl;
	vct.erase(vct.begin() + 5);
	print_normal();


	cout<<"erase :vct.begin() ,vct.begin() + 5"<<endl;
	vct.erase(vct.begin(), vct.begin() + 5);
	print_normal();

	vct.clear();

	cout<<"vct.size() == " << vct.size() << "\tafter vct.clear()";
	
	for(int i = 0 ; i < vct.size(); i++)
		cout<<vct[i];


	cout<<endl;
	return 0;
}

