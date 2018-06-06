#include <iostream>
using namespace std;
int main()
{
	char temp[1001];
	while(cin>>temp)
	{
		for(int f=0;temp[f]=='o'&&temp[f];f++);
		int l=strlen(temp);
		for(int r=0;r<l&&temp[l-1-r]=='o';r++);
		if(r==f&&l-r-f==3&&temp[f]=='z'&&temp[f+1]=='o'&&temp[f+2]=='j')
			cout<<"Accepted"<<endl;
		else if(r==2*f&&l-r-f==4&&temp[f]=='z'&&temp[f+1]=='o'&&temp[f+2]=='o'&&temp[f+3]=='j')
			cout<<"Accepted"<<endl;
		else
			cout<<"Wrong Answer"<<endl;
	}
	return 0;
}
