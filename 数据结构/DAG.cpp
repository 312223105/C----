#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

vector<int> maps[1000];
queue<int> q;
int degr[1000];
int N = 0,M = 0;
int mark[1000];

void DAG()
{
	for(int i = 0; i < N; i++)
		if(degr[i] == 0)
			q.push(i);

	int first = 0, second = 0;
	int zz = 0;
	while(!q.empty())
	{
		first = q.front();
		mark[first] = zz;
		zz++;
		for(int i = 0; i < maps[first].size(); i++)
		{
			second = maps[first][i];
			degr[second]--;
			if(degr[second] == 0)
				q.push(second);
		}
		q.pop();
	}
}

int main()
{
 	clock_t start,finish;
   	double totaltime;
   	start=clock();

	cin>>N>>M;
	int a,b;
	memset(mark,-1,sizeof(mark));
	for(int i = 0; i< N; i++)
		degr[i] = 0;

	for(int i = 0; i < M; i++)
	{
		cin>>a>>b;
		//a==>b
		maps[a].push_back(b);
		degr[b]++;
	}
	
	DAG();

	bool flag = true;
	for(int i = 0; i < N; i++)
		if(degr[i] != 0)
			flag = false;

	if(flag == true)
		cout<<"YES"<<endl;

	for(int i = 0; i< N; i++)
		cout<<mark[i]<<" "<<endl;


	finish=clock();
   	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   	cout<<"\neee"<<totaltime<<"  s!"<<endl;
}
