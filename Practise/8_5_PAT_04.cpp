#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int maps[105][105];
int visited[105];
vector<pair<int,int> > roads;
int main()
{
	memset(maps,0,sizeof(maps));
	

	int N,M;
	cin>>N>>M;
	int a,b;
	for(int i = 0 ; i < M; i++)
	{
		cin>>a>>b;
		maps[a][b] = 1;
		maps[b][a] = 1;
		roads.push_back(make_pair(a,b));
	}

	vector<pair<int,int> >::iterator first = roads.begin(),end = roads.end(),it;
	for(it = first; it != end; it++)
	{
		memset(visited,0,sizeof(visited));
		int a = it->first;
		int b = it->second;
		//cout<<"a = "<<a<<" b = "<<b;
		maps[a][b] = 0;
 		
 		queue<int> can_connected_q;
		can_connected_q.push(a);
		visited[a] = 1;
		
		//cout<<"访问：";
		while(!can_connected_q.empty())
		{
			int front = can_connected_q.front();
			//cout<<endl<<a<<" ";
			can_connected_q.pop();

			int next;
			//cout<<"i for loop :" ;
			for(int i = 1; i <= N; i ++)
			{
				
				if(i != front && maps[front][i] != 0 && visited[i] == 0)
				{
					//cout<<i<<" ";
					can_connected_q.push(i);
					visited[i] = 1;
				}
			}
		}

		bool flag = true;//是否仍然连通

		for(int i = 1; i <= N; i++)
			if(visited[i] == 0)
				flag = false;

 		//遍历，看是否为连通图，全部遍历完成
		if(flag == false)
		{
			if(a > b)
				cout/*<<"ans = "*/<<b<<" "<<a<<endl;
			else
				cout/*<<"ans = "*/<<a<<" "<<b<<endl;
		}

		maps[a][b] = 1;
		maps[b][a] = 1;
	}
}
