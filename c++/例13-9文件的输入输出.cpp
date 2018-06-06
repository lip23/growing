#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	ifstream infile("l13-9.txt",ios::in);
	int a[10],i;
	if(!infile)
	{
		cout<<"open error"<<endl;
		exit(1);
	}
	for(i=0;i<10;i++)
		infile>>a[i];
	int m=0;
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<endl;
		if(a[i]>a[m])
			m=i;
	}
	
	cout<<"max="<<a[m]<<endl;
	cout<<"i="<<m+1<<endl;
	infile.close();
	return 0;
}

