#include <iostream>
using namespace std;

int data[20] = {1,3,4,1,6,7,3,5,9,1,5,7,0,5,4,2,1,10,11,-1};

int temp[20];


//合并的范围[lo,hi)
void mergo(int data[],int lo,int mid,int hi)
{
	int i = lo,j = mid;
	for(int k = lo; k < hi; k++)
		temp[k] = data[k];

	for(int k = lo; k < hi; k++)
	{
		if(i >= mid) 
			data[k] = temp[j++];
		else if(j >= hi)
			data[k] = temp[i++];
		else if(temp[i] > temp[j])
		{
			data[k] = temp[j++];
		}
		else
			data[k] = temp[i++];
	}
}

//排序范围[lo,hi)
void sort(int data[],int lo,int mid,int hi)
{
	cout<<"lo = "<<lo<<" mid = "<<mid<<" hi = "<<hi<<endl;
	if(lo+1 == hi)
		return;
	sort(data,lo,lo+(mid-lo)/2,mid);
	sort(data,mid,mid+(hi-mid)/2,hi);
	mergo(data,lo,mid,hi);
}
int main()
{
	sort(::data,0,(20-0)/2,20);

	for(int i = 0; i < 20; i++)
	{
		cout<<data[i]<<" ";
	}

	return 0;
}
