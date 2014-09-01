#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<int> data[1000];

bool marks[1000];

void bfs()
{
	queue<int> que;
	que.push(1);
	marks[1] = true;

	while(!que.empty())
	{
		int front = que.front();
		cout<<front<<" ";
		que.pop();

		for(int i = 0; i < data[front].size(); i++)
		{
			if(marks[data[front][i]] != true)
			{
				marks[data[front][i]] = true;
				que.push(data[front][i]);
			}
		}
	}
}

int main()
{
	memset(data,0,sizeof(data));
	memset(marks,0,sizeof(marks));
	int N;cin>>N;
	int a,b;
	for(int i = 0; i < N; i++)
	{
		cin>>a>>b;
		data[a].push_back(b);
		data[b].push_back(a);
	}

	bfs();

	return 0;
}
