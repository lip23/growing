#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int b[4][4];
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j]=3*i+2*j-6;
	cout<<"b[4][4]:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			cout<<setw(4)<<b[i][j];
		cout<<endl;
	}
	int h2=0;
	for(j=0;j<4;j++)
		h2=h2+b[1][j];
	cout<<"h2="<<h2<<endl;
	double al4;
	int l4=0;
	for(i=0;i<4;i++)
		l4=l4+b[i][3];
	al4=double(l4)/4;
	cout<<"al4="<<al4<<endl;
	int c=0;
	for(i=0;i<4;i++)
		if(b[i][i]<0)
			c++;
	cout<<"c="<<c<<endl;
	return 0;
}