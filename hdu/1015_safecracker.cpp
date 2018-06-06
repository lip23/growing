#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	int n;
	char code[12];
	cin>>n>>code;
	while(!(strcmp(code,"END")==1&&n==0))
	{
		int l=strlen(code)-1;
		for(int i1=l;i1>=0;i1--)
		{
			for(int i2=l;i2>=0;i2--)
			{
				if(i2==i1)i2--;
				for(int i3=l;i3>=0
	}
	return 0;
}