#include <iostream>
using namespace std;
int main()
{
	
	
	for(int i=2992;i<10000;i++)
	{
		int t1=i,t2=i,t3=i;
		int c1=0,c2=0,c3=0;
		while(t1!=0)
		{
			c1+=t1%10;
			t1/=10;
			if(t2!=0)
			{c2+=t2%12;t2/=12;}
			if(t3!=0)
			{c3+=t3%16;t3/=16;}
		}
		if(c1==c2&&c1==c3)
			cout<<i<<endl;
	}
	return 0;
}

