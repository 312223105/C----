#include <iostream>
#include <stack>
#include <cstdio>


using namespace std;

void printNum(int num)
{
	switch(num)
	{
		case 0: cout<<"zero"; break;
		case 1: cout<<"one"; break;
		case 2: cout<<"two"; break;
		case 3: cout<<"three";break;
		case 4: cout<<"four"; break;
		case 5: cout<<"five"; break;
		case 6: cout<<"six"; break;
		case 7: cout<<"seven"; break;
		case 8: cout<<"eight"; break;
		case 9: cout<<"nine"; break;
		default : break;
	}
}

int main()
{
	char c;
	int sum = 0;
	while(scanf("%1s", &c) == 1)
	{
		sum += (c - '0');
	}
	stack<int> st;
	while(sum >= 10)
	{
		st.push(sum % 10);
		sum /= 10;
	}
	
	printNum(sum);
	while(!st.empty())
	{
		cout<<" ";
		printNum(st.top());
		st.pop();

	}
	cout<<endl;
}