#include <iostream>
using namespace std;

int main()
{
	char buf;
	int letter[26];
	char lett[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	memset(letter,0,sizeof(letter));
	while(cin.get(buf))
	{
		if(buf=='\n')
		{
			for(int i=0;i<26;i++)
				cout<<lett[i]<<':'<<letter[i]<<endl;
			memset(letter,0,sizeof(letter));
			cout<<endl;
		}	
		else if(buf>=97&&buf<=122)
			letter[buf-97]++;
	}
	return 0;
}

