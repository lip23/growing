#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int c=0;
	int m=0;
	cout<<setiosflags(ios::left);
	cout<<"1000֮�ڵ�����������"<<endl;
	for(int i=1;i<1000;i++)
	{
		for(int a=2;a<i;a++)
			for(int b=2;b<i;b++)
				if(a*b==i)
					c++;
		if(c==0)
		{
			cout<<setw(5)<<i;
			m++;
			if(m%16==0)
				cout<<endl;
		}
		c=0;
	}
	cout<<endl<<"����"<<m<<"��"<<endl;
	return 0;
}
