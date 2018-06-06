#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout<<"将输入的罗马数据化为10进制数。假设罗马数据中只使用如下7个基值字母："<<endl;
	cout<<"M、D、C、L、X、V、I，分别用来表示1000、500、100、50、10、5、1。"<<endl;
	cout<<"如，罗马数据表示10进制的87。"<<endl;
	string l="LXXXVII";
	int t=0;
	for(int i=0;l[i];i++)
		switch(l[i])
		{
		case'M':t=t+1000;break;
		case'D':t=t+500;break;
		case'C':t=t+100;break;
		case'L':t=t+50;break;
		case'X':t=t+10;break;
		case'V':t=t+5;break;
		case'I':t=t+1;break;
		}
	cout<<"l="<<"LXXXVII"<<endl;
	cout<<"t="<<t<<endl;
	return 0;
}
