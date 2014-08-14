#include <iostream>
using namespace std;

int data[1000];
int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>data[i];

	int temp;
	//sort increasing
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}

	for(int i = 0 ; i < n - 1; i++)
		cout<< data[i] << " < ";
	cout<< data[n - 1] << endl;
}