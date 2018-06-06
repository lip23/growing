#include <iostream>
using namespace std;

int f(int a,int n)
{
	if(n==1)return a;
	return f(a,n/2)*f(a,n-n/2);
}

int main()
{
	char p;
	do{
		cout<<"please enter a and n:  ";
		int n,a;
		cin>>a>>n;
		cout<<"the result is: ";
		cout<<f(a,n)<<endl;	
		cout<<"do you want to continue ? y=='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
}
