#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

map<int,vector<pair<string,int> > > total_to_stu;

int scores[100005][10];
int equles[100005];

bool cmp(const pair<string,int> &a, const pair<string,int> &b)
{
	//cout<<"cmp: " <<"a.second = "<<a.second <<" b.second "<<b.second<<endl<<endl;;
	int a_index = a.second;
	int b_index = b.second;

	for(int i = 9; i >= 0 ; i--)
	{
		if(scores[a_index][i] > scores[b_index][i])
		{
			// ans = true;
			return true;
		}
		else if (scores[a_index][i] == scores[b_index][i])
			continue;
		else 
			return false;
	}
	equles[a_index] = b_index;
	equles[b_index] = a_index;
	return false;
}

int main()
{
	memset(scores,0,sizeof(scores));
	memset(equles,0,sizeof(equles));

	int N,M;
	cin>>N>>M;

	for(int i = 0; i < N; i++)
	{
		string name;
		cin>>name;
		int total = 0;
		int _score;
		for(int j = 0; j< M; j++)
		{
			cin>>_score;
			scores[i][j] = _score;
			total -= _score;
		}
		total_to_stu[total].push_back(make_pair(name,i));
	}

	map<int,vector<pair<string,int> > >::iterator it,first,end;
	first = total_to_stu.begin();
	end = total_to_stu.end();
	// for(it = first; it != end; it++)
	// {
	// 	cout<<"total = "<<it->first;
	// 	vector<pair<string,int> >::iterator itVct, firstVct,endVct;
	// 	firstVct = it->second.begin();
	// 	endVct = it->second.end();
	// 	for(itVct = firstVct; itVct != endVct ; itVct++)
	// 		cout<<"\tname :"<<itVct->first<<"  index = "<<itVct->second;
	// 	cout<<endl;
	// }

	int rank_num = 1;
	int count = 1;
	for(it = first; it != end; it++)
	{
		if(it->second.size() == 1)
		{
			rank_num = count;
			cout<<rank_num<<" "<<it->second[0].first<<endl;
			rank_num ++;
			count++;
		}
		else
		{
			sort(it->second.begin(),it->second.end(),cmp);
			vector<pair<string,int> >::iterator itVct, firstVct,endVct;
			firstVct = it->second.begin();
			endVct = it->second.end();
			for(itVct = firstVct ; itVct != endVct; itVct++)
			{
				// cout<<rank_num<<" "<<itVct->first<<endl;
				if(equles[itVct->second] == 0)
				{
					rank_num = count;
					cout<<rank_num<<" "<<itVct->first<<endl;
					rank_num++;
				}
				else
				{
					cout<<rank_num<<" "<<itVct->first<<endl;
					// if(equles[it->second] == equles[(it+1)->second])
					// {
						
					// }
				}
				count++;

			}
		}
		
	}
}
