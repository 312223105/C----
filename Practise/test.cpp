// #include <iostream>
// #include <time.h>
// #include <string>
// #include <cstdio>
// #include <cstdlib>


//程序运行时间测试
/*
#define cycle 300

int main()
{
	clock_t start,finish;
   	double totaltime;
   	start=clock();
   	unsigned n = 0;
   	n--; 
   	unsigned test = 0;
	for(unsigned i = 0; i < cycle ; i++)
		for(unsigned j = 0; j < cycle; j++)
			for(unsigned k = 0; k < cycle; k++)
				test++;	
	cout<<test <<endl;

	finish=clock();
   	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   	cout<<"\neee"<<totaltime<<"  s!"<<endl;

}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    string line;
    while(getline(cin,line))
    {
      if(line.size() == 0)  continue;
      string::size_type begin = 0,end = 0;
      while(end != line.npos)
      {
        
        end = line.find("/",begin);
        if(end != line.npos)
        {
          cout<<"begin = "<<begin<<" end = "<<end<<"   ";
          cout<<line.substr(begin,end - begin)<<endl;
          // cout<<sub<<endl;
          begin = end+1;
        }


      }
      cout<<line.substr(begin,line.size() - begin);

    }

    return 0;
}
