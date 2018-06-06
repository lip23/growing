#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	string keyword;
	cin>>keyword;
	int lk=keyword.size();
	int tag[26];
	memset(tag,0,sizeof(tag));
	char code[26],lcode[26],start='A';
	for(int i=0;i<lk;i++)
	{
		code[keyword[i]-'A']=start++;
		tag[keyword[i]-'A']=1;
	}
	for(int i=25;i>=0;i--)
		if(!tag[i]) code[i]=start++;
	for(int i=0;i<26;i++)lcode[i]=code[i]+32;
	char temp;
	cin.get();
	while(cin.get(temp)){
		if(islower(temp))printf("%c",lcode[temp-97]);
		else if(isupper(temp))printf("%c",code[temp-65]);
		else printf("%c",temp);
	}
	return 0;
}
