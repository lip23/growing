#include <iostream>
#include <string>
using namespace std;
int main()
{
	char temp[101];
	while(cin>>temp,strcmp(temp,"E"))
	{
		int z=0,o=0,j=0;
		for(int i=0;temp[i];i++)
			if(temp[i]=='Z')
				z++;
			else if(temp[i]=='O')
				o++;
			else if(temp[i]=='J')
				j++;
		while(z||o||j)
		{
			if(z)
			{
				cout<<'Z';
				z--;
			}
			if(o)
			{
				cout<<'O';
				o--;
			}
			if(j)
			{
				cout<<'J';
				j--;
			}
		}
		cout<<endl;
	}
	return 0;
}



