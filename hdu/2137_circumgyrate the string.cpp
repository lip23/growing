#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	string data;
	int t;
	while(cin>>data>>t){
		t%=8;
		t=t<0?t+8:t;
		switch(t){
			case 0:
				cout<<data<<endl;
				break;
			case 1:
				for(int i=data.size()-1;i>=0;--i)cout<<setw(i+1)<<data[i]<<endl;
				break;
			case 2:{
				int w=data.size()/2+1;
				for(int i=data.size()-1;i>=0;--i)cout<<setw(w)<<data[i]<<endl;
				break;
			}
			case 3:{
				int l=data.size();
				for(int i=data.size()-1;i>=0;--i)cout<<setw(l-i)<<data[i]<<endl;
				break;
			}
			case 4:{
				string tdata(data.rbegin(),data.rend());
				cout<<tdata<<endl;
				break;
			}
			case 5:{
				int l=data.size();
				for(int i=0;i<l;++i)cout<<setw(l-i)<<data[i]<<endl;
				break;
			}
			case 6:{
				int w=data.size()/2+1;
				for(int i=0;i<data.size();++i)cout<<setw(w)<<data[i]<<endl;
				break;
			}
			case 7:
				for(int i=0;i<data.size();++i)cout<<setw(i+1)<<data[i]<<endl;
				break;
		}
	}
	return 0;
}
