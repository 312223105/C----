#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1000];
bool marked[1000];

void DFS(vector<int> graph[], int v)
{
	cout<<e<<"->";
	marked[v] = true;
	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(!marked[*it])
			DFS(graph,*it);
	}
}

int main()
{
	memset(marked,0,sizeof(marked));
	int V, E;
	cin>>V>>E;
	int v1, v2;
	while(V--)
	{
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	DFS(::graph,graph[v1][0]);
}