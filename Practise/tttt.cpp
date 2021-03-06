#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

char pinyin[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void print(int num)
{
	printf("%s",pinyin[num]);
}
int main()
{
	char str;
	int result = 0;
	while(scanf("%1s",&str) == 1)
	{
		int temp = 0;
		sscanf(&str,"%d",&temp);
		result += temp;
	}


	stack<int> q_num;
	while(result > 9)
	{
		q_num.push(result % 10);
		result /= 10;
	}
	
	print(result);
	while(!q_num.empty())
	{
		int num = q_num.top();
		q_num.pop();
		printf(" ");
		print(num);
	}
}






/*struct bao
{
	int v;
	int w;
}data[1000];

int N,M;
int ans;
int rest_v;
void dfs(int m,int w)
{
	if(m == N)
	{
		if(ans < w)
		{
			ans = w;
		}
		return;
	}

	if(rest_v > data[m].v)
	{
		dfs(m + 1, w + data[m])
		dfs(m + 1, w);
	}
	else
	{
		dfs(m + 1, w);
	}
}

int main()
{
	cin>>N,M;
	rest_v = M;
	for(int i = 0 ; i < N; i++)
	{
		cin>>data[i].v>>data[i].m=w;
	}

	dfs(0,0);
	cout<<ans;
}*/