#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char str_in[100] = "1 2 3 4 5 6 7 8 9 0";
	char str_out[100];
	int count_in = 0,count_out = 0;
	int data;
	int len = strlen(str_in);
	while(count_in <= len)
	{
		count_in += sscanf(str_in+count_in,"%d",&data) + 1;
		count_out += sprintf(str_out+count_out,"%d ",data);
	}

	printf("输出为: \t%s\n",str_out);
	



	//cout<<endl;
	return 0;
}