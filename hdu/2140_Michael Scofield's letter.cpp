#include <iostream>
#include <string>
using namespace std;
int main()
{
	char data[128];
	memset(data,0,sizeof(data));
	data['b']=' '; data['q']=',';data['t']='!';data['m']='l';data['i']='e';
	data['c']='a';data['a']='c';data['e']='i';data['l']='m';
	string text;
	while(cin>>text){
		for(int i=0;i<text.size();i++)
			if(data[text[i]])cout<<data[text[i]];
			else cout<<text[i];
		cout<<endl;
	}
	return 0;
}
