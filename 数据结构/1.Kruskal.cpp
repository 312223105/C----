#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> edge;
const int MAX_SIZE = 10003;
int flag[MAX_SIZE];
// vector<int> graph[MAX_SIZE];
queue<edge> mst;
priority_queue<pair<double,edge>, vector<pair<double,edge> >, greater<pair<double,edge> > > pq;

int id[1000];
int sz[1000];
int count = 0;

int find(int p)
{
	int proot = p;
	while(proot != id[p])
		proot = id[p];
	return proot;
}

void union_(int p,int q)
{
	int proot = find(p);
	int qroot = find(q);

	if(proot == qroot)
		return;

	if(sz[proot] > sz[qroot])
	{
		id[qroot] = proot;
		sz[proot] += sz[qroot];
	}
	else
	{
		id[proot] = qroot;
		sz[qroot] += sz[proot];
	}

	::count--;
}

void init_(int n)
{
	::count = n;
	for(int i = 0 ;i < n; i++)
	{
		sz[i] = 1;
		id[i] = i;
	}

}

bool connected(int v, int w)
{
	if(find(v) != find(w))
		return false;
	else
		return true;
}


void kruskalMST(int n)
{
	double ans = 0;
	while(!pq.empty() && mst.size() < n - 1)
	{
		pair<double,edge> min = pq.top();
		pq.pop();
		int v = min.second.first, w = min.second.second;
		if(connected(v, w))	continue;

		cout<<v<<"->"<<w<<"   "<<min.first<<endl;
		union_(v, w);
		ans += min.first;
		mst.push(make_pair(v, w));
	}
	cout<<ans<<endl;
}


int main()
{
	int V, E;
	cin>>V>>E;

	init_(V);

	for(int i = 0; i < E; i++)
	{
		int a, b;
		double c;
		cin>>a>>b>>c;
		pq.push(make_pair(c, make_pair(a, b)));
	}

	kruskalMST(V);

	// while(!mst.empty())
	// {
	// 	pair<int, int> e = mst.front();
	// 	mst.pop();
	// 	cout<<e.first<<"->"<<e.second<<endl;
	// }
}