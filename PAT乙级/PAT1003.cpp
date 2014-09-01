#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
	{
		char str1[1000];
		scanf("%s",str1);
		int len = strlen(str1);
		bool flag = true;
		int j = 0;
		int index1 = 0;
		for(; j < len; j++)
		{
			//cout<<str1[j];
			if(str1[j] == 'P')
				break;
			if(str1[j] != 'A')
				flag = false;
		}
		//cout<<"j = "<<j<<endl;
		index1 = j;
		if(!flag)
		{
			printf("NO\n");
			continue;
		}

		for(j += 1; j < len; j++)
		{
			//cout<<str1[j];
			if(str1[j] == 'T')
				break;
			if(str1[j] != 'A')
				flag = false;
		}
		//cout<<"j = "<<j<<endl;
		int index2 = j;
		if(!flag || index2 - index1 == 1)
		{
			printf("NO\n");
			continue;
		}

		for(j += 1; j < len; j++)
		{
			//cout<<str1[j];
			if(str1[j] != 'A')
				flag = false;
		}
		//cout<<"j = "<<j<<endl;
		int index3 = j;
		if(!flag)
		{
			printf("NO\n");
			continue;
		}
		else
			printf("YES\n");

	}
}