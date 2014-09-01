#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAX_SIZE = 100004;
vector<int> graph[MAX_SIZE];
int pathTo[MAX_SIZE];//关键   path[n] = m 代表走到'n'的上一步是'm'
int marked[MAX_SIZE];

void DFS(vector<int> graph[], int v)
{
	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(!marked[*it])
		{
			marked[*it] = true;
			pathTo[*it] = v;
			DFS(graph, *it);
		}
	}
}
stack<int>* DepthFirstPath(int begin, int end)
{
	memset(marked, 0, sizeof(marked));
	memset(pathTo, 255, sizeof(pathTo));
	DFS(graph, begin);
	if(!marked[end])	return NULL;
	stack<int> *paths = new stack<int>;
	for(int x = end; x != begin; x = pathTo[x])
	{
		paths->push(x);
	}
	paths->push(begin);
	return paths;
}

int main()
{
	int V, E;
	cin>>V >>E;
	int v1, v2;
	int i;
	for(i = 0; i < E; i++)
	{
		cin>>v1 >>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v2);
	}
	cout<<endl<<"i = "<<i<<endl;
	cin>>v1>>v2;
	cout<<endl<<v1<<"---->>>>"<<v2<<endl;
	stack<int>* paths;
	paths = DepthFirstPath(v1, v2);
	if(paths != NULL)
	{
		while(!paths->empty())
		{
			cout<<paths->top()<<" - > ";
			paths->pop();
		}
	}
	else
		cout<<"no Path";
	cout<<endl;

	return 0;
}