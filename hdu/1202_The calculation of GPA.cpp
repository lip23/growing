#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=EOF)
	{
	double * point=new double[n];
	double * grade=new double[n];
	int * ratio=new int[n];
	double p=0,r=0;
	double gpa=0;
	for(int i=0;i<n;i++)
	{
		cin>>point[i]>>grade[i];
		switch((int)grade[i]/10)
		{
		case 10:
		case 9:ratio[i]=4;break;
		case 8:ratio[i]=3;break;
		case 7:ratio[i]=2;break;
		case 6:ratio[i]=1;break;
		};
		if(grade[i]>=0&&grade[i]<60)
			ratio[i]=0;
		if(grade[i]!=-1)
		{
			p+=point[i];
			r+=ratio[i]*point[i];
		}
	}
	for(i=0;i<n;i++)
		if(grade[i]!=-1)
		{
			cout<<setiosflags(ios::showpoint);
			cout.precision(3);
			cout<<r/p<<endl;
			break;
		}
		else
			if(i==n-1)
				cout<<"-1"<<endl;
	}
	return 0;
}





		

