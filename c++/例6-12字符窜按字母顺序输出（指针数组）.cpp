#include <iostream>
#include <string>
using namespace std;
int main()
{
	void sort(char * name[],int n);
	void print(char * name[],int n);
	char * name[]={"BASIC","FORTRAN","C++","Pascal","COB0L"};
	int n=5;
	sort(name,n);
	print(name,n);
	cout<<name[1]<<endl;
	return 0;
}


void sort(char * name[],int n)
{
	int m;
	char* temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			m=i;
			if(strcmp(name[m],name[j])>0)
				m=j;
		}
		temp=name[i];
		name[i]=name[m];
		name[m]=temp;
	}
}


void print(char *name[],int n)
{
	for(int i=0;i<n;i++)
		cout<<name[i]<<endl;
}
