#include <iostream>
using namespace std;
int main()
{
	int m,n;
	int sum(int,int);
	cout<<"��������m��n֮��������ۼӺ�"<<endl;
	cout<<"����������������m��n��m<=n"<<endl;
	cin>>m>>n;
	while(m>n)
	{
		cout<<"������������������������룺"<<endl;
		cin>>m>>n;
	}
	cout<<"sum="<<sum(m,n)<<endl;
	return 0;
}

int sum(int m,int n)
{
	if(m==n)
		return m;
	else
		return sum(m,n-1)+n;
}

