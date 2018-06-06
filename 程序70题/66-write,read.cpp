#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	double d[15];
	for(int i=1;i<=15;i++)
		d[i-1]=i*i+0.5;
	ofstream outfile("66f1.txt",ios::binary);
	if(!outfile)
		cout<<"open erro"<<endl;
	outfile.write((char*)d,sizeof(d));
	outfile.close();
	for(i=1;i<=10;i++)
		d[i-1]=10*i+0.5;
	d[10]=357.9;
	outfile.open("66f2.txt",ios::binary);
	if(!outfile)
		cout<<"open erro"<<endl;
	outfile.write((char*)d,11*sizeof(double));
	outfile.close();
	double c[26];
	ifstream infile("66f1.txt",ios::in||ios::binary);
	if(!infile)
		cout<<"open erro"<<endl;
	infile.read((char*)c,15*sizeof(double));
	infile.close();
	infile.open("66f2.txt",ios::in||ios::binary);
	if(!infile)
		cout<<"open erro"<<endl;
	infile.read((char*)&c[15],11*sizeof(double));
	infile.close();
	void sort(double*,int);
	sort(c,26);
	outfile.open("66f3.txt",ios::binary);
	if(!outfile)
		cout<<"open erro"<<endl;
	outfile.write((char*)c,sizeof(c));
	outfile.close();
	double f[26];
	infile.open("66f3.txt",ios::binary||ios::in);
	infile.read((char*)f,sizeof(f));
	for(i=0;i<26;i++)
		cout<<f[i]<<endl;
	return 0;
}

void sort(double* a,int n)
{
	int m;
	double t;
	for(int i=0;i<n;i++)
	{
		m=i;
		for(int j=i+1;j<n;j++)
			if(a[m]>a[j])
				m=j;
		t=a[i];
		a[i]=a[m];
		a[m]=t;
	}
}
