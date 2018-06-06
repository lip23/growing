#include <iostream>
using namespace std;

int main()
{
	int i,n;
	cout<<"输入正整数i和n，由程序负责从i开始找起，连续找出n个素数"<<endl;
	cout<<"请输入i=";
	cin>>i;
	cout<<"请输入n=";
	cin>>n;
	int a,b,c,d=0,m=0;
	for(a=i;m<n;a++)
	{
		for(b=1;b<a;b++)
			for(c=1;c<a;c++)
				if(b*c==a)
					d++;
		if(d==0)
		{
			cout<<a<<endl;
			m++;
		}
		d=0;
	}
	return 0;
}
