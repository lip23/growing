#include <iostream>
using namespace std;
int main()
{
	cout<<" 求下述三个序列的累加和（每一序列各累加n项，正整数n通过cin从键盘输入）"<<endl;
	cout<<"s1 = 1/5 + 1/4 + 3/11 + 2/7 + 5/17 + 3/10 + 7/23 + …"<<endl;
	cout<<"s2 = 2/1 + 3/2 + 5/3  + 8/5  + 13/8 + 21/13 + 34/21 + …"<<endl;
	cout<<"s3 = 1/1 - 3/(1+4) + 5/(1+4+7) - 7/(1+4+7+10) + 9/(1+4+7+10+13) - …"<<endl;
	int n;
	double s1=0;
	double a1=0,b1=0;
	cout<<"请输入您要求的前n项的和：n= ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a1=i;
		b1=3*i+2;
		s1=s1+a1/b1;
	}
	cout<<"s1="<<s1<<endl;
	cout<<"请输入您要求的前n项的和：n= ";
	cin>>n;
	double a2=2,b2=1;
	double s2=2;
	double temp;
	for(i=2;i<=n;i++)
	{
		temp=b2;
		b2=a2;
		a2=a2+temp;
		s2=s2+a2/b2;
	}
	if(n==0)
		s2=0;
	cout<<"s2="<<s2<<endl;
	double s3=0;
	double a3=0,b3=0;
	int m=-1;
	cout<<"请输入您要求的前n项的和：n= ";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		m=m*(-1);
		a3=2*i-1;
		b3=(3*i-1)*i/2;
		s3=s3+a3/b3*m;
	}
	cout<<"s3="<<s3<<endl;
	return 0;
}

