#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct temp
{
	int i;
	double d;
	char c;
};

int main()
{
	ofstream outfile("65read.txt",ios::binary);
	if(!outfile)
		cout<<"open erro";
	temp t[15];
	for(int k=1;k<16;k++)
	{
		t[k-1].i=2*k-1;
		t[k-1].d=k*k+k-9.8;
		t[k-1].c='H'+k;
	}
	outfile.write((char*)t,sizeof(t));
	outfile.close();
	ifstream infile("65read.txt",ios::in||ios::binary);
	if(!infile)
		cout<<"open erro"<<endl;
	temp tt[15];
	cout<<setiosflags(ios::left);
	infile.read((char*)tt,sizeof(tt));
	for(k=0;k<15;k++)
		cout<<setw(8)<<tt[k].i<<setw(8)<<tt[k].d<<setw(8)<<tt[k].c<<endl;
	infile.close();
	return 0;
}
