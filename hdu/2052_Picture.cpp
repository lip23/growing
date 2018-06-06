#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int h,w;
	//bool first=true;
	while(cin>>h>>w){
		//if(!true)cout<<endl;
		cout.fill('-');
		cout<<'+'<<setw(h+1)<<'+'<<endl;
		cout.fill(' ');
		for(int i=0;i<w;i++)
			cout<<'|'<<setw(h+1)<<'|'<<endl;
		cout.fill('-');
		cout<<'+'<<setw(h+1)<<'+'<<endl;
		cout<<endl;
	}
	return 0;
}
