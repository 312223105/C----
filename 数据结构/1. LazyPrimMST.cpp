/*

Prim算法计算最小生成树（MST）的延时实现
最小生成树讨论的都是有权无向图，且没有自环，权值非负
且必须为连通图，否则将生成最小生成森林

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <list>

using namespace std;

const int MAX_SIZE = 10004;
vector<pari<double, int> > graph[MAX_SIZE];
bool marked[MAX_SIZE];
queue<pair<int, int> > MST;
list<pair<int, int> > others;

void visit(vector<pari<double, int> > graph, int v)
{
	marked[v] = true;

	for(vector<pari<double, int> >::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(!marked[it->second])
			others.insert(make_pair(v, it->second));
	}
}

void prim(vector<pari<double, int> > graph)
{
	memset(marked, 0, sizeof(marked));

	visit(graph, 0);
	while(!others.empty())
	{
		pair<int, int> front = others.front();
		others.pop();
		int v = front.first, w = front.second;
		for(vector<pari<int, double> >::iterator it = graph[v].begin(); it != graph[v].end(); it++)
		{
			if(marked[v] && marked[w])	continue;

			if(!marked[v])	
		}
		
	}
}
