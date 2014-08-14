#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char strs[10000][10];
vector<char*> asc2_vct[256][256];

int main()
{
	int N;
	cin>>N;
	char first_char = 0;
	char second_char = 0;
	for(int i = 0 ; i < N; i++)
	{
		cin>>strs[i];
		first_char = strs[i][0];
		second_char = strs[i][1];
		asc2_vct[first_char][second_char].push_back(strs[i]);
	}

	for(int i = 97 ;i < 123; i++)
	{
		for(int j = 97 ;j < 123; j++)
			if(asc2_vct[i][j].size() != 0)
				if(asc2_vct[i][j].size() == 1)
					cout<<asc2_vct[i][j][0];
				else
				{
					sort(asc2_vct[i][j].begin(),asc2_vct[i][j].end());
					for(std::vector<char*>::iterator it = asc2_vct[i][j].begin(); it != asc2_vct[i][j].end(); it++)
						cout<<*it<<endl;
				}
	}

	return 0;

}
