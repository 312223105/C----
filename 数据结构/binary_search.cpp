#include <iostream>
#include <cstring>

using namespace std;
#define MAX_SIZE 100005
int data[MAX_SIZE] = {1, 22, 33, 52, 57, 69, 73, 88, 90, 100, 160, 193, 223, 246, 259, 273, 281, 476, 543, 634, 856, 923, 1466, 2456, 3556, 23465, 34732};

//还可以用while循环，不管改变l r，并判断l w 是否越界等，进行搜索

int binary_search(int l,int r,int key)
{

	cout<<"l = " <<l <<" r = "<<r<<endl;
	if(l + 1 == r)
		return data[l] == key ? r : -1;

	int mid = (l + r ) / 2;
	if(data[mid] == key)
		return mid;

	if(data[mid] > key)
		return binary_search(l,mid,key);
	else
		return binary_search(mid + 1, r, key);
}

int main()
{
	int num;
	cin>>num;
	// memset(data,0,sizeof(data));
	int i;
	for(i = 0; i < MAX_SIZE; i++)
	{
		if(data[i] == 0)
			break;

	}
	cout<<binary_search(0, ++i, num);

	return 0;
}
