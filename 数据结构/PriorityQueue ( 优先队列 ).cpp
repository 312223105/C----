#include <iostream>
#include <vector>

using namespace std;

vector<int> queu;

int main()
{
	// int N;
	// cin>>N;

	int data[10] = {1,2,3,4,5,6,7,8,9,10};

	queu.push_back(-1);
	for(int i = 0; i < 10; i++)
	{
		queu.push_back(data[i]);
		int new_index = queu.size() - 1;
		while(new_index > 1 && queu[new_index] < queu[new_index / 2 ])
		{
			int temp = queu[new_index];
			queu[new_index] = queu[new_index / 2];
			queu[new_index / 2] = temp;
			new_index = new_index / 2;
		}
	}
	vector<int>::iterator first,it,end;
	it = first = queu.begin();
	end = queu.end();
	for(; it != end; it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
