#include <iostream>
using namespace std;
int main()
{
	double d,v;
	while(cin>>v>>d)
	{
		for(int m=0;v>0;m++)
			v-=d;
		//cout<<"m="<<m<<endl;
		int i=1;
		while(i*(i+1)/2<m)
			i++;
		cout<<m+i-1<<endl;
	}
	return 0;
}
