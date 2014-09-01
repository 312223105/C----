//P358  『Algorithm』
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;
const int MAX_SIZE = 150003;
map<string, int> indexs;
string names[MAX_SIZE];
vector<int> graph[MAX_SIZE];
bool marked[MAX_SIZE];
int pathTo[MAX_SIZE];


void BFS(vector<int> graph[], int begin)
{
	queue<int> que;
	que.push(begin);
	marked[begin] = true;
	pathTo[begin] = begin;
	// cout<<names[begin];
	while(!que.empty())
	{
		int front = que.front();
		que.pop();

		for(vector<int>::iterator it = graph[front].begin(); it != graph[front].end(); it++)
		{
			if(!marked[*it])
			{
				// cout<<" -> "<<names[*it];
				pathTo[*it] = front;
				marked[*it] = true;
				que.push(*it);
			}
		}
		// cout<<endl;
	}
}

int main(int argn,char *args[])
{
	if(argn < 2)
	{
		cout<<"无输入文件"<<endl;
	}

	char *filePath = args[1];
	ifstream in(filePath);
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	string line;
	int index = 0;
	while(getline(cin,line))
    {
    	queue<int> que;
        if(line.size() == 0)  continue;
        string::size_type begin = 0,end = 0;
        while(end != line.npos)
        {
	        end = line.find("/",begin);
	        if(end != line.npos)
	        {
	        	string str = line.substr(begin,end - begin);
	        	if(indexs.count(str) != 1)
	        	{
	        		que.push(index);
	        		names[index] = str;
	        		indexs[str] = index++;
	        	}
	        	else
	        	{
	        		que.push(indexs[str]);
	        	}
	        	begin = end+1;
	        }
        }
        string str = line.substr(begin,line.size() - begin);
		if(indexs.count(str) != 1)
		{
			que.push(index);
			indexs[str] = index++;
		}
		else
    	{
    		que.push(indexs[str]);
    	}
		int root = que.front();
		que.pop();

		while(!que.empty())
		{
			int front = que.front();
			que.pop();

			graph[root].push_back(front);
			graph[front].push_back(root);
		}
    }

    cin.rdbuf(cinbuf);


    cout<<"input A(. to exit):";
    string A;
    getline(cin, A);
    memset(pathTo, 255, sizeof(pathTo));
    memset(marked, 0, sizeof(marked));

    int indexA;
    if(indexs.count(A) == 0)
	{
		cout<<"not in database"<<endl;
	}
	else
	{
		indexA = indexs[A];
		BFS(graph,indexA);	
	}
    
    cout<<"input searchStr:"<<endl;
    string searchStr;
    while(getline(cin, searchStr))
    {
    	cout<<"get a searchStr:"<<searchStr<<endl;
    	if(indexs.count(searchStr) == 0)
    	{
    		cout<<"not in database"<<endl;
    	}
    	else
    	{
    		int indexS = indexs[searchStr];
    		if(marked[indexS])
    		{
    			stack<int> ans;
    			while(pathTo[indexS] != indexA)
    			{
    				cout<<"\t"<<names[indexS]<<endl;
    				ans.push(indexS);
    				indexS = pathTo[indexS];
    			}
    			cout<<endl;
    			cout<<"stack ANS"<<endl;
    			ans.push(indexS);

    			cout<<endl;
    			while(!ans.empty())
    			{
    				cout<<"\t"<<names[ans.top()]<<endl;
    				ans.pop();
    			}
    		}
    		else
    		{
    			cout<<"not linked"<<endl;
    		}
    	}
    }
	return 0;
}
