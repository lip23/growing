#include <iostream>
using namespace std;

int divided(int n,int m)
{
	if(n==1||m==1)return 1;
	else if(n<m)return divided(n,n);
	else if(n==m)return 1+divided(n,m-1);
	else if(n>m) return divided(n-m,m)+divided(n,m-1);
}

int main()
{
	char p;
	do{
		cout<<"please enter the number divided :";
		int num;
		cin>>num;
		int res=divided(num,num);
		cout<<"the result is: "<<res<<endl;
		cout<<"do you want to continue: n=='no' :";
		cin>>p;
	}while(p!='n');
	return 0;
} 
