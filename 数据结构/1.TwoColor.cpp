//二分图问题，也就是仅适用两种颜色，是否可以使任意两个相邻顶点颜色不同

#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1003;
vector<int> graph[MAX_SIZE];
bool marked[MAX_SIZE];
bool isTwoColorable = true;
bool colors[MAX_SIZE];

void DFS(vector<int> graph[], int v)
{
	marked[v] = true;

	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(!marked[*it])
		{
			colors[*it] = !colors[v];
			DFS(graph, *it);
		}
		else if(colors[*it] == colors[v])
			isTwoColorable = false;
	}
}

int main()
{
	int V, E;
	cin>>V >>E;
	int v1, v2;
	for(int i = 0; i < E; i++)
	{
		cin>>v1 >>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for(int i = 0; i < V; i++)
	{
		if(!marked[i])
			DFS(graph, i);
	}

	if(isTwoColorable)
		cout<<"yes";
	else
		cout<<"no";

	return 0;
}