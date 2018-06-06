#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<"dig[10][10]:"<<endl;
	int i,j;
	int a[10];
	for(i=0;i<10;i++)
		a[i]=0;
	char dig[10][10];
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			dig[i][j]=48+rand()%10;
			cout<<setw(3)<<dig[i][j];
			switch(dig[i][j])
			{
			case'0':a[0]++;break;
			case'1':a[1]++;break;
			case'2':a[2]++;break;
			case'3':a[3]++;break;
			case'4':a[4]++;break;
			case'5':a[5]++;break;
			case'6':a[6]++;break;
			case'7':a[7]++;break;
			case'8':a[8]++;break;
			case'9':a[9]++;break;
			}
		}
		cout<<endl;
	}
	cout<<"字符0出现的次数："<<a[0]<<endl;
	cout<<"字符1出现的次数："<<a[1]<<endl;
	cout<<"字符2出现的次数："<<a[2]<<endl;
	cout<<"字符3出现的次数："<<a[3]<<endl;
	cout<<"字符4出现的次数："<<a[4]<<endl;
	cout<<"字符5出现的次数："<<a[5]<<endl;
	cout<<"字符6出现的次数："<<a[6]<<endl;
	cout<<"字符7出现的次数："<<a[7]<<endl;
	cout<<"字符8出现的次数："<<a[8]<<endl;
	cout<<"字符9出现的次数："<<a[9]<<endl;
	return 0;
}