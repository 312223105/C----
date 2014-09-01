//char 保存字符串做法
/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str1[10005];
char str2[10005];
bool mark[256];
int main()
{
	memset(mark,false,sizeof(mark));
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for(int i = 0; i < len2; i++)
	 	mark[str2[i]] = true;

	for(int i = 0; i < len1; i++)
		if(mark[str1[i]] != true)
			cout<<str1[i]; 

}
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string str1(10000,'\0');
string str2(10000,'\0');
bool mark[256];
int main()
{
	memset(mark,false,sizeof(mark));
	getline(cin,str1);
	getline(cin,str2);

	for(int i = 0; i < str2.size(); i++)
		mark[str2[i]] = true;
	for(string::iterator it = str1.begin(); it != str1.end(); it++)
		if(mark[*it] != true)
			cout<<*it;
	return 0;
}
