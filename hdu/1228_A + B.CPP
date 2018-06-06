#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a[6];
	int i=0;
	int t1=0,t2=0;
	while(cin>>a[i])
	{
		if(a[0]!="=")
		{
			if(a[i]=="zero")t1=t1*10+0;
			else if(a[i]=="one")t1=t1*10+1;
			else if(a[i]=="two")t1=t1*10+2;
			else if(a[i]=="three")t1=t1*10+3;
			else if(a[i]=="four")t1=t1*10+4;
			else if(a[i]=="five")t1=t1*10+5;
			else if(a[i]=="six")t1=t1*10+6;
			else if(a[i]=="seven")t1=t1*10+7;
			else if(a[i]=="eight")t1=t1*10+8;
			else if(a[i]=="nine")t1=t1*10+9;
			else if(a[i]=="+")
			{
				t2=t1;
				t1=0;
			}
		}
		else
			if(t1==0&&t2==0)
				break;
			else
			{
				cout<<t1+t2<<endl;
				t1=0;
				t2=0;
			}
	}
	return 0;
}

