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
