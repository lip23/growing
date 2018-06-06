#include <iostream>
#include <iomanip>
using namespace std;


int k=888;		char c='T'; 


void f1() 
{
	int i=31;		
	float k=3.1;  
	cout<<"f1: k,c,i =>"<<setw(6)<<k<<setw(6)<<c<<setw(6)<<i<<endl;
}


void f2() 
{
	int i=52;		
	double c=5.2; 
	cout<<"f2: k,c,i =>"<<setw(6)<<k<<setw(6)<<c<<setw(6)<<i<<endl;
} 

 
int main() 
{
	cout<<"main: k,c =>"<<setw(6)<<k<<setw(6)<<c<<endl; 
	f1();		
	f2();
	return 0;
}
