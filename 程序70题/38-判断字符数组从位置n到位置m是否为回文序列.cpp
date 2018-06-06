#include <iostream>
using namespace std;
int main()
{
	char s[20];
	bool f(char s[],int,int);
	bool f2(char s[],int,int);
	int m,n;
	cin>>s;
	cin>>m>>n;
	if(f(s,m,n))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	if(f2(s,m,n))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}

bool f(char s[],int d1,int d2)
{
	d1--;
	d2--;
	int m=(d2-d1)/2,p=1;
	for(int i=0;i<=m;i++)
		if(s[d1+i]!=s[d2-i])
			p=0;
	if(p)
		return true;
	else
		return false;
}

bool f2(char s[],int d1,int d2)
{
	if(d1<d2)
		if(s[d1-1]==s[d2-1])
			return f2(s,d1+1,d2-1);
		else
			return false;
	else
		return true;
}
