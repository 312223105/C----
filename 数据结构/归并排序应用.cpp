struct node 
{
	int n;
	int index;
}data[100005];

for(int i = 0 ; i < n; i++)
	data[i].index = i + 1;

int first, second;
int len;
int sublen;

list<node> lst;

while(sublen != len)
{
	int n = len % sublen != 0 ? len / sublen : len / sublen + 1;
	for(int i = 0; i < n ; i = i + 2)
	{
		first = i * sublen;
		second = (i + 1) * sublen;
		while(first != (i + 1) * sublen && second != (i + 2) * sublen)
		{
			if(data[first].n > data[second].n)
			{
				cout<<"("<<data[first].index<<","<<data[second].index<<")";
				lst.push_back(data[second]);
				second++;
			}
			else
			{
				lst.push_back(data[first]);
				first++;
			}
		}
		for(int i = first; i < (i + 2) * sublen; i++)
		{
			node temp = list.front();
			data[i] = temp;
			list.pop_front();
		}
	}
	sublen *= 2;
}