#include <iostream>
#include <string>
using namespace std;
int main()
{
	char c1[10],c2[10],c3[10];
	cout<<"������3����ĸ����С��9�Ĺ�����"<<endl;
	cin>>c1;
	cin>>c2;
	cin>>c3;
	void small(char s[],char y[],char c[]);
	small(c1,c2,c3);
	return 0;
}


void small(char c1[],char c2[],char c3[])
{
	if(strcmp(c1,c2))
		strcpy(c2,c1);
	if(strcmp(c3,c2))
		strcpy(c2,c3);
	cout<<"the smallest string is "<<c2<<endl;
}

	