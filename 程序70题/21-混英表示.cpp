#include <iostream>
#include <string>
using namespace std;
int main()
{
	char eng[10][6]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string s;
	cout<<"请输入一个整数n："<<endl;
	cin>>s;
	int l=strlen(s.c_str());
	for(int i=0;i<l;i++)
	{
		int n;
		n=s[i]-48;
		cout<<eng[n]<<"(1";
		for(int j=0;j<l-i-1;j++)
			cout<<0;
		if(l-i==1)
			cout<<")";
		else
			cout<<")-";
	}
	cout<<endl;
	return 0;
}