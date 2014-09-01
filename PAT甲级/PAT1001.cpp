#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int ans,a,b;
	scanf("%d%d", &a, &b);

	ans = a + b;
	char str[100];

	if(ans < 0)
	{
		ans = -ans;
		printf("-");
	}
	sprintf(str,"%d",ans);
	int len = strlen(str);
	if(len <= 3)
		printf("%s",str);
	else
	{
	
		len -= 3;
		int a = len % 3;
		int i = 0;
		for(; i < len; i++)
		{
			printf("%c",str[i]);
			if((i+1) % 3 == a)
				printf(",");
		}
		printf("%s",&str[i]);
	}

	return 0;
}