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
	cout<<"������ѧ����������ѧ��"<<endl;
	input_date(d,n);
	output_date(d,n);
	do
	{
		cout<<"��������Ҫ���ҵ�ѧ�����������������������0��"<<endl;
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
		cout<<"�����޴���"<<endl;

}


void output_date(string d[][2],int n)
{
	cout<<setiosflags(ios::left);
	cout<<"�������ѧ��������:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
			cout<<setw(10)<<d[i][j];
		cout<<endl;
	}
}
