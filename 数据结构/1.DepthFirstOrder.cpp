/*

反向后序遍历即是拓扑排序序列
无论从哪一个点开始排序，结果都是正确的

*/


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int MAX_SIZE = 10004;
vector<int> graph[MAX_SIZE];
stack<int> reversePost; //反向后序遍历
queue<int> pre;
queue<int> post;
bool marked[MAX_SIZE];

void DFS(vector<int> graph[], int x)
{
	marked[x] = true;
	pre.push(x);

	for(vector<int>::reverse_iterator it = graph[x].rbegin(); it != graph[x].rend(); it++)
	{
		if(!marked[*it])
		{
			DFS(graph, *it);
		}
	}

	reversePost.push(x);
	post.push(x);
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
	}


	for(int i = 0; i < V; i++)
	{
		if(!marked[i])
		{
			DFS(graph, i);
		}
	}

	cout<<"前序遍历:\n"<<pre.front();
	pre.pop();
	while(!pre.empty())
	{
		cout<<"  "<<pre.front();
		pre.pop();
	}

	cout<<endl;

	cout<<"后序遍历：\n"<<post.front();
	post.pop();
	while(!post.empty())
	{
		cout<<"  "<<post.front();
		post.pop();	
	}

	cout<<endl;

	cout<<"反向后序遍历：\n"<<reversePost.top();
	reversePost.pop();
	while(!reversePost.empty())
	{
		cout<<"  "<<reversePost.top();
		reversePost.pop();	
	}	

	cout<<endl;
	return 0;
}