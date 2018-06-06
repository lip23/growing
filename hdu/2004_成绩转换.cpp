#include <iostream>
#include <string>
using namespace std;
int main()
{
	string rank="EDCBAA";
	double grade;
	while(cin>>grade){
		if(grade>100||grade<0){
			cout<<"Score is error!"<<endl;
			continue;
		}
		if(grade<60)
			cout<<'E'<<endl;
		else
			cout<<rank[(grade-50)/10]<<endl;
	}
	return 0;
}
