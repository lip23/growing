#include <iostream>
using  namespace std;

class student
{
private:
	int num;
	int age;
	int score;
	static int count;//累计需要统计的学生人数
	static float sum;//总分
public:
	
	void total();
	static float average();
	student(int,int,int);
};

int main()
{
	student s[3]={student(1001,18,71),student(1002,19,78),student(1003,20,98)};
	int n;
	cout<<"请输入您要求平均成绩的学生数n=";
	cin>>n;
	for(int i=0;i<n;i++)
		s[i].total();
	cout<<student::average()<<endl;
	return 0;
}

student::student(int n,int a,int s):num(n),age(a),score(s){};

float student::sum=0;

int student::count=0;

void student::total()
{
	count++;
	sum=sum+score;
}

float student::average()
{
	return sum/count;
}
	
