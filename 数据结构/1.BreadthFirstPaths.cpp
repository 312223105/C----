#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int MAX_SIZE = 1001;
vector<int> graph[MAX_SIZE];
int marked[MAX_SIZE];
int pathTo[MAX_SIZE];

void BFS(vector<int> graph[], int v)
{
	memset(marked, 0, sizeof(marked));
	memset(pathTo, 255, sizeof(pathTo));
	queue<int> que;
	que.push(v);
	marked[v] = true;
	pathTo[v] = v;
	while(!que.empty())
	{
		int front = que.front();
		que.pop();
		for(vector<int>::iterator it = graph[front].begin(); it != graph[front].end(); it++)
		{
			if(!marked[*it])
			{
				marked[*it] = true;
				pathTo[*it] = front;
				que.push(*it);
			}
		}
	}
}

stack<int>* breadthFirstPaths(vector<int> graph[], int begin, int end)
{
	BFS(graph, begin);
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
	int V, E, v1, v2;
	cin>>V >>E;
	for(int i = 0; i < E; i++)
	{
		cin>>v1 >>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int begin, end;
	cin>>begin >>end;
	stack<int> *paths;
	paths = breadthFirstPaths(graph, begin, end);
	if(paths != NULL)
	{
		int front = paths->top();
		paths->pop();
		cout<<front;
		while(!paths->empty())
		{
			front = paths->top();
			paths->pop();
			cout<<" -> "<<front;
		}
	}

}