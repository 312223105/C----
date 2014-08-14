#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1000
int marks[MAX_SIZE];

// struct node
// {
// 	int from;
// 	int to;
// 	int value;
// } maps[MAX_SIZE];
//first toNode  ;second value;
vector<pair<int,int> >maps;

vector<pair<int,int> > MST;


bool cmp(const node &a,const node &b)
{
	if(a.value <= b.value)
		return true;
	else
		return false;
}


int main()
{
	int N,M;
	int a,b.v;
	cin>>N>>M;

	for(int i = 1 ;i <= M; i++)
	{
		cin>>a>>b>>v;
		maps[a].push_back(make_pair(b,v));
	}
	for(int i = 1;i <= N; i++)
		marks[i] = i;

	sor(maps + 1,maps + 1 + M,cmp);

	int first = maps[1].from;
	//marks[first] = first;

	int count = 1;

	while(count < N)
	{

	}



	return 0;
}
