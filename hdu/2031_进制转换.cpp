#include <iostream>
using namespace std;
int main()
{
	char data[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	double rr;
	int n;
	while(cin>>rr>>n)
	{
		bool flag=true;
		if(rr<0)
			flag=false;
		unsigned int r=abs(rr);
		char cha[12];
		int k=0;
		while(r)
		{
			cha[k]=data[r%n];
			r/=n;
			k++;
		}
		if(rr==0)
			cout<<0;
		else
		{
			if(!flag)
				cout<<'-';
			for(k--;k>=0;k--)
				cout<<cha[k];
		}
		cout<<endl;
	}

	return 0;
}
