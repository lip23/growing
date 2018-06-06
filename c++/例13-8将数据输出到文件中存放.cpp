#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("f1.txt",ios::out);
	int a[3];
	if(!outfile)
	{
		cout<<"open error"<<endl;
		exit(1);
	}
	cout<<"enter 3 integer numbers:"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
		outfile<<a[i]<<" ";
	}
	outfile.close();
	return 0;
}
	

