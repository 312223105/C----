#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int MAX_SIZE = 1003;
vector<int> graph[MAX_SIZE];
int marked[MAX_SIZE];
int count = 0;

int nowRoot;
void DFS(vector<int> graph[], int v)
{
	marked[v] = nowRoot;

	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(marked[*it] == -1)
			DFS(graph, *it);
	}
}

int N;
void cc()
{
	for(int i = 0; i < N; i++)
	{
		if(marked[i] == -1)
		{
			nowRoot = i;
			::count++;
			DFS(graph, i);
		}
	}
}

int main()
{
	memset(marked, 255, sizeof(marked));
	cin>>N;
	int E;
	cin>>E;
	int v1, v2;
	for(int i = 0; i < E; i++)
	{
		cin>>v1 >>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	cc();
	cout<<"CC_count = "<<::count<<endl;
}