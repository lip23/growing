#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<setiosflags(ios::left);//输入数据左对齐，该设置对其后的输出均有效（除非从新设置）
	for(int i=1;i<=7;i+=2)
	{
		if(i<7)
		{
			for(int n=1;n<=i;n++)
				cout<<setw(2)<<"*";//setw只对其后一个输出项有效
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