#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

void display()
{
	cout.fill('-');
	cout.width(80);
	cout<<'-'<<endl;
}

int main()
{
	string data;
	int count=0;
	ifstream in("1088.txt");
	while(getline(in,data)){
		istringstream stream(data);
		string temp;
		while(stream>>temp){
			if(temp=="<br>"){cout<<endl;count=0;}
			else if(temp=="<hr>"){
				if(count)cout<<endl;
				display();
				count=0;
			}
			else{
				if(count+temp.size()>=80){cout<<endl;count=0;}
				if(count)cout<<' ';
				cout<<temp;
				count+=temp.size()+1;
			}	
		}	
	}
	cout<<endl;
	in.close();
	return 0;	
}
