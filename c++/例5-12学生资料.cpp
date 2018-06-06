#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	void input_date(string d[][2],int n);
	void output_date(string d[][2],int);
	void search(string d[][2],string l,int n);
	int n=5;
	int m=2;
	string d[5][2];
	string l;
	cout<<"请输入学生的姓名和学号"<<endl;
	input_date(d,n);
	output_date(d,n);
	do
	{
		cout<<"请输入您要查找的学生的姓名（若想结束请输入0）"<<endl;
		cin>>l;
		search(d,l,n);
	}while(l!="0");
	return 0;
}


void input_date(string d[][2],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			cin>>d[i][j];
}


void search(string d[][2],string l,int n)
{
	string s;
	for(int i=0;i<n;i++)
	{
		if(d[i][0]==l)
		{
			s=l;
			cout<<d[i][0]<<"  "<<d[i][1]<<endl;
			break;
		}
	}
	if(s!=l&&l!="0")
		cout<<"本班无此人"<<endl;

}


void output_date(string d[][2],int n)
{
	cout<<setiosflags(ios::left);
	cout<<"您输入的学生数据有:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
			cout<<setw(10)<<d[i][j];
		cout<<endl;
	}
}
