#include <iostream>
using namespace std;
int main()
{
	void f1(int);
	void f2(int);
	void f3(int);
	f1(19);
	cout<<endl;
	f2(12709);
	cout<<endl;
	f3(12709);
	cout<<endl;
	return 0;
}

void f1(int n) 
{	
	if(n>1) 
		f1(n/2); 
	cout<<n%2;
}


void f2(int n) 
{
	if(n>0) 
	{
		char t=n%10+65;
		cout<<t<<t;
		f2(n/10);  
	}
}

void f3(int n) 
{
	if(n>0) 
	{
		f2(n/10); 
		char t=n%10+65;
		cout<<t<<t;
	}
}


