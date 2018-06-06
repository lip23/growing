#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student
{
	string num;
	string name;
	float score[3];
	float ave;
};


int main()
{
	void input(student &);
	void print(student &);
	void average(student &);
	void sort(student s[],int);
	student s[3];
	int i;
	int n=3;
	for(i=0;i<3;i++)
	{
		cout<<"请输入学生 "<<i+1<<" 的学号 姓名 成绩1 成绩2 成绩3 "<<endl;
		input(s[i]);
	}
	cout<<setiosflags(ios::left)<<"这几个学生的数据是："<<endl;
	cout<<setw(8)<<"学号"<<setw(8)<<"姓名"<<setw(8)<<"成绩1"<<setw(8)<<"成绩2"<<setw(8)<<"成绩3"<<setw(8)<<"平均分"<<endl;
	for(i=0;i<3;i++)
	{
		average(s[i]);
		print(s[i]);
	}
	sort(s,n);
	cout<<"按平均分排名："<<endl;
	cout<<setw(8)<<"学号"<<setw(8)<<"姓名"<<setw(8)<<"成绩1"<<setw(8)<<"成绩2"<<setw(8)<<"成绩3"<<setw(8)<<"平均分"<<endl;
	for(i=0;i<3;i++)
	{
		print(s[i]);
	}
	return 0;
}

void input(student &s)
{
	cin>>s.num>>s.name>>s.score[0]>>s.score[1]>>s.score[2];
}

void print(student &s)
{
	cout<<setw(8)<<s.num<<setw(8)<<s.name<<setw(8)<<s.score[0]
		<<setw(8)<<s.score[1]<<setw(8)<<s.score[2]<<setw(8)<<s.ave<<endl;
}

void average(student &s)
{
	s.ave=(s.score[0]+s.score[1]+s.score[2])/3;
}


void sort(student s[],int n)
{
	student p;
	int j,k;
	for(int m=0;m<n;m++)
	{
		k=m;
		for(j=m+1;j<n;j++)
		{
			if(s[k].ave<s[j].ave)
				k=j;
		}
		if(k!=m)
		{
			p=s[m];
			s[m]=s[k];
			s[k]=p;
		}
	}
}
			

