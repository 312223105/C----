/*

通过深度优先遍历搜索判断存在有环
关键细节：
Stack<int> cycle;
bool onStack[MAX_SIZE];
int pathTo[MAX_SIZE];
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAX_SIZE = 10004;

vector<int> graph[MAX_SIZE];
int onStack[MAX_SIZE];
stack<int>* cycle;
bool marked[MAX_SIZE];
int pathTo[MAX_SIZE];

void DFS(vector<int> graph[], int x)
{
	// x为当前访问的点，接下来访问所有相邻点
	marked[x] = true;
	onStack[x] = true;
	for(vector<int>::iterator it = graph[x].begin(); it!= graph[x].end(); it++)
	{
		// if(cycle != NULL) return;
		if(!marked[*it])
		{
			pathTo[*it] = x;
			DFS(graph, *it);
		}
		else if(onStack[*it])
		{
			//因为检测出已经有路径可以从x走到*it
			//所有通过顺着pathTo走就可以把路径走完
			//从当前点走到*it的路径

			cycle = new stack<int>;
			for(int i = x; i != *it ; i = pathTo[i])
			{
				cycle->push(i);
			}
			cycle->push(*it);
			cycle->push(x);
			//如果只需要简单判断是否有环，不用遍历整个图，在适当位置进行判断cycle是否为空，然后退出即可
		}
	}
	onStack[x] = false;
}

int main()
{

	memset(marked, 0, sizeof(marked));
	memset(onStack, 0, sizeof(onStack));
	memset(pathTo, 255, sizeof(pathTo));
	cycle = NULL;


	int V, E;
	cin>>V >>E;
	int v1, v2;
	for(int i = 0; i < E; i++)
	{
		cin>>v1 >>v2;
		graph[v1].push_back(v2);
	}

	for(int i = 0; i < V; i++)
	{
		if(!marked[i])
		{
			DFS(graph, i);
		}
	}

	if(cycle != NULL)
	{
		while(!cycle->empty())
		{
			cout<<cycle->top()<<" -> ";
			cycle->pop();
		}

		cout<<endl;
	}
	else
	{
		cout<<"no cycle";
	}

}


