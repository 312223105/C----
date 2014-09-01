#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1003;
vector<int> graph[MAX_SIZE];
int marked[MAX_SIZE];
bool hasCycle = false;
int V,E;

void DFS(vector<int> graph[], int root, int father)
{
	marked[root] = 1;

	for(vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++)
	{
		if(marked[*it] == 0)
			DFS(graph, *it, root);
		else if(*it != father)
			hasCycle = true;
	}
}

int main()
{
	cin>>V>>E;
	int v1, v2;
	for(int i = 0; i < E; i++)
	{
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	DFS(graph, v1, v1);
	if(hasCycle)
		cout<<"yes";
	else
		cout<<"no";

	return 0;
}