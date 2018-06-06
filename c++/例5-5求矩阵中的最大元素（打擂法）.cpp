#include <iostream>
using namespace std;
int main()
{
	int max,row=0,colum=0;
	int a[3][4]={{5,12,23,56},{19,28,37,46},{-12,-34,6,8}};
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{
			if(a[i][j]>a[row][colum])
			{
				row=i;
				colum=j;
			}
		}
		max=a[row][colum];
		cout<<"row="<<row<<endl;
		cout<<"colum="<<colum<<endl;
		cout<<"max="<<max<<endl;
		return 0;
}
