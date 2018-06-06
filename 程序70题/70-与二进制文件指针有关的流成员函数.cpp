#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=rand()%100+9;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	ofstream outfile("70.txt",ios::binary);
	if(!outfile)
		cout<<"open erro"<<endl;
	outfile.write((char*)a,sizeof(a));
	outfile.close();
	ifstream infile("70.txt",ios::in||ios::binary);
	if(!infile)
		cout<<"open erro"<<endl;
	int b[10];
	for(i=1;i<=10;i++)
	{
		infile.seekg(-i*sizeof(int),ios::end);
		infile.read((char*)&b[i-1],sizeof(int));
		cout<<b[i-1]<<" ";
	}
	cout<<endl;
	infile.close();
	return 0;
}

