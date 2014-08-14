#include <iostream>
#include <list>

using namespace std;
list<int> lst;

struct node
{
	int addr;
	int data;
	int next;
}data[100000];

int main()
{
	int first, N, K;
	cin>>first>>N>>K;
	int addr, d, nxt;
	for(int i = 0; i < N; i ++)
	{
		cin>>addr >>d >>nxt;
		data[addr].addr = addr;
		data[addr].data = d;
		data[addr].next= nxt;
	}
	list<int> lst;
	nxt = first;

	while(nxt != -1)
	{
		lst.push_back(data[nxt]);
		nxt = data[nxt].next;
		
	}

	for(list<node>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		node x = (node)*it;
		cout<<x.add <<" " <<x.data <<" " <<x.next<<endl; 
	}
	stack<node> stk;
	int count = 0;
//  int rest = K - 1;
	for(list<node>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		stk.push()

		if(count % K == K - 1)
		{
			node x,next;
			for(int i = 0 ; i < K; i++)
			{
				x = stk.front();
				stk.pop();
				if(x.next != -1)
				{
					
				}
				cout<<x.addr <<" " << x.data << 
			}
		}
		count++;
	}


	for(int i )


	int K;
	cin>>K;

	int len = lst.size();
	for(list<int>::iterator it = lst.begin(); it != lst.end();
}