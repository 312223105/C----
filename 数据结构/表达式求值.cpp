#include <iostream>
#include <stack>
#include <string>
using namespace std;


void fun1()
{
	//输入格式：( 4 / ( 9 - ( 4 * 2 ) ) )
	stack<int> vals;
	stack<char> oprs;

	char str;

	while(cin>>str)
	{
		if(str == '(') 
			;
		else if(str == '-' || str == '+' || str == '*' || str == '/')
			oprs.push(str);
		else if(str == ')')
		{
			int val1 = vals.top();
			vals.pop();
			int val2 = vals.top();
			vals.pop();
			char opr = oprs.top();
			oprs.pop();

			int result = 0;
			if(opr == '-')
			{
				result = val2 - val1;
			}
			else if(opr == '+')
			{
				result = val1 + val2;
			}
			else if(opr == '*')
			{
				result = val1 * val2;
			}
			else if(opr == '/')
			{
				result = val2 / val1;
			}
			vals.push(result);
		}
		else
		{
			int num = str - '0';
			vals.push(num);
		}
	}

	cout<<"ans = "<<vals.top()<<endl;
}


//未完成
void fun2()
{
	//输入格式：4 / 2 - 4 * 2
	stack<int> vals;
	stack<char> oprs;

	char str;

	while(cin>>str)
	{
		if(str == '(') 
			;
		else if(str == '-' || str == '+' || str == '*' || str == '/')
			oprs.push(str);
		else if(str == ')')
		{
			int val1 = vals.top();
			vals.pop();
			int val2 = vals.top();
			vals.pop();
			char opr = oprs.top();
			oprs.pop();

			int result = 0;
			if(opr == '-')
			{
				result = val2 - val1;
			}
			else if(opr == '+')
			{
				result = val1 + val2;
			}
			else if(opr == '*')
			{
				result = val1 * val2;
			}
			else if(opr == '/')
			{
				result = val2 / val1;
			}
			vals.push(result);
		}
		else
		{
			int num = str - '0';
			vals.push(num);
		}
	}

	cout<<"ans = "<<vals.top()<<endl;
}
int main()
{
	fun1();

	return 0;
}