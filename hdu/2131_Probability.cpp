#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

char t;

bool pre(char c)
{
	return tolower(c)==tolower(t);
}

int main()
{
	
	string data;
	while(cin>>t>>data){
		double length=data.size();
		double times=count_if(data.begin(),data.end(),pre);
		cout.setf(ios::fixed);
		cout.precision(5);
		cout<<times/length<<endl;
	}
	return 0;
}
