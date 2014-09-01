//测试点2 错误   测试点4内存超限


#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

set<int> maps[1005];
int marks[1005];
int try_to_delete;

void dfs(int n)
{
	marks[n] = true;
	for(set<int>::iterator it = maps[n].begin(); it != maps[n].end(); it++)
	{
		if(marks[*it] == false)
		{
			//cout<<*it<<" --> ";
			marks[*it] = true;
			dfs(*it);
		}
	}
}

int main()
{
	
	int N,M,K;
	cin>>N>>M>>K;
	int a,b;
	for(int i = 0; i < M; i++)
	{
		cin>>a>>b;
		maps[a].insert(b);
		maps[b].insert(a);
	}

	int k;
	vector<int> vct;
	for(int i = 0; i < K; i++)
	{
		cin>>k;
		vct.push_back(k);
	}
	for(vector<int>::iterator it = vct.begin() ;it != vct.end(); it++)
	{
		memset(marks,0,sizeof(marks));
		marks[*it] = true;
		int n = *(maps[*it].begin());
		int ans = 0;
		while(n != -1)
		{
			//cout<<"dfs("<<n<<")"<<endl;
			dfs(n);
			int j;
			for(j = 1; j <= N; j++)
			{
				if(marks[j] == false)
				{
					n = j;
					break;
				}
			}
			if(j == N + 1)
				n = -1;
			else
				ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}
