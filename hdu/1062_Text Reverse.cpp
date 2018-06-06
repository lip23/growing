#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.get();
	//setbuf(stdin,NULL);
	for(int i=0;i<n;i++)
	{
		string temp;
		getline(cin,temp);
		int pos=0,front=0;
		while(temp[pos])
		{
			if(isspace(temp[pos]))
			{
				for(int cur=pos-1;cur>=front;cur--)
					cout<<temp[cur];
				cout<<temp[pos];
				front=pos+1;
			}
			pos++;
		}
		for(pos--;!isspace(temp[pos])&&pos>=front;pos--)
			cout<<temp[pos];
		cout<<endl;
	}
	return 0;
}