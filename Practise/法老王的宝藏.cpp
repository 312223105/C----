#include <iostream>
#include <vector>

using namespace std;

int N,C;
int w[10005];
int v[10005];
int now_w;
int ans = -1;
void dfs(int m,int now)
{
	cout<<"m = "<<m <<" now = "<<now <<" now_w = "<<now_w<<endl;
	if(m == N)
	{
		if(now > ans)
			ans = now;
		return;
	}

	if(now_w + w[m] > C)
	{
		dfs(m + 1,now);
	}
	else
	{
		now_w += w[m];
		dfs(m + 1,now + v[m]);
		now_w -= w[m];
		dfs(m + 1, now);
	}
}

int main()
{
	cin>>N>>C;
	now_w = 0;

	for(int i = 0 ; i < N; i++)
	{
		cin>>w[i]>>v[i];
	}
	dfs(0,0);

	cout<<ans<<endl;

	return 0;
}
