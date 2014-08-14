#include <iostream>
using namespace std;

int data[20] = {1,3,4,1,6,7,3,5,9,1,5,7,0,5,4,2,1,10,11,-1};

void print()
{
	for(int i = 0; i < 20 ;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}
void sort(int first,int last)
{
	if(first == last)
		return;

}
int main()
{
	print();

	int first = 0,second = 1;
	int now = 0;
	int temp;
	while(first == second)
	{
		int count = 20 / (second - first);
		while(second < 20 && first < 20)
		{
			if(data[first] > data[second])
			{
				temp = data[first];
				data[first] = data[second];
				data[second] = temp;
			}
		}
		for(int i = 0; i < count; i++)
		{
			for(int j = first; j <= last; j++)
			{

			}
		}
		while()
	}
}
