#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<setiosflags(ios::left);//������������룬�����ö������������Ч�����Ǵ������ã�
	for(int i=1;i<=7;i+=2)
	{
		if(i<7)
		{
			for(int n=1;n<=i;n++)
				cout<<setw(2)<<"*";//setwֻ�����һ���������Ч
			cout<<endl;
		}
		else if(i=7)
		{
			for(int m=7;m>=1;m-=2)
			{
				for(int n=1;n<=m;n++)
					cout<<setw(2)<<"*";
				cout<<endl;
			}
		}
	}
	return 0;
}