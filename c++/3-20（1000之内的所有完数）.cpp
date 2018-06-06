#include <iostream>
using namespace std;
int main()
{
	int m;
	int p=0;
	int q=0;
	for(int i=1;i<=1000;i++)
	{
		for(int x=1;x<=1000;x++)
			for(int y=1;y<=1000;y++)
			{
				if(x*y==i&&x>=y)
				{
					p=p+x;
					q=q+y;
				}
			}
			if(p+q==2*i)
			{
				cout<<i<<"is all number"<<endl;
			}
			p=0;
			q=0;
	}
	return 0;	
}

	
