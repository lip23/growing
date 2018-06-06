#include <iostream>
#include <string>
using namespace std;

bool found_same(string &s)
{
	for(int i=0;i<s.size()-1;i++)
		if(s[i]==s[i+1]&&(s[i]!='e'&&s[i]!='o'))
			return false;
	return true;
}

bool trans(string &data,bool *fag)
{
	bool p=false;
	for(int i=0;i<data.size();i++)
		if(data[i]=='a'||data[i]=='e'||data[i]=='i'||data[i]=='o'||data[i]=='u'){
			fag[i]=1;
			p=true;
		}
		else fag[i]=0;
	//cout<<"p="<<p<<endl;
	return p;
}

bool found_three(bool *fag,int n){
	for(int i=0;i<n-2;i++)
		if(fag[i]==fag[i+1]&&fag[i]==fag[i+2])
			return false;
	return true;
}

int main()
{
	string data;
	while(cin>>data,data!="end"){
		bool found=false;
		if(found_same(data)){
			//cout<<'1'<<endl;
			bool *fag=new bool[data.size()];
			if(trans(data,fag)&&found_three(fag,data.size())){
				found=true;
				cout<<'<'<<data<<"> is acceptable.\n";
				delete []fag;
			}
		}
		if(!found) cout<<'<'<<data<<"> is not acceptable.\n";
	}
	return 0;
}
