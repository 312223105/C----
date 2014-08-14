#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char keys_to[8][4] = {  'a','b','c','0',
						'd','e','f','0',
						'g','h','i','0',
						'j','k','l','0',
						'm','n','o','0',
						'p','q','r','s',
						't','u','v','0',
						'w','x','y','z'};

string sample[1005];
int marks[1005];
int main()
{
	memset(marks,0,sizeof(marks));
	string input;
	cin>>input;
	int n;
	cin>>n;
	for(int i = 0 ; i < n; i++)
	{
		cin>>sample[i];
		// if(sample[i].size() < input.size())
		// 	marks[i] = 1;
	}


	string::iterator it,first,end;
	first = input.begin();
	end = input.end();

	int index = -1;
	size_t len_input = input.size();
	// for(int i = 0; i < n;i++)
	// 	cout<<marks[i]<<" "<<endl;
	for(it = first; it != end; it++)
	{
		int num = *it - '2';
		cout<<*it;
		//cout<<"num = "<<num<<endl;
		if(num < 0)
		{
			// cout<<*it<<endl;
			continue;
		}
		else
			index++;


		for(int j = 0 ; j < n; j++)
		{
			bool flag = 0;
			if(marks[j] == 1)
				continue;
			//cout<<sample[j]<<endl;
			if(sample[j].size() < index + 1)
			{
				marks[j] = 1;
				continue;
			}
			for(int i = 0 ; i < 4; i++)
			{
				if(keys_to[num][i] == sample[j][index] && keys_to[num][i] != '0')
				{
					//cout<<"key_to - sample = "<<keys_to[num][i] - sample[j][index]<<"  "<<sample[j][index]<<endl;
					flag = 1;
					break;
				}
			}
			if(flag != 1)
				marks[j] = 1;
		}
		
	}

	for(int i = 0 ; i < n; i++)
	{
		if(marks[i] == 0)
			cout<<sample[i]<<endl;
	}

}
