#include <iostream>
using  namespace std;

class student
{
private:
	int num;
	int age;
	int score;
	static int count;//�ۼ���Ҫͳ�Ƶ�ѧ������
	static float sum;//�ܷ�
public:
	
	void total();
	static float average();
	student(int,int,int);
};

int main()
{
	student s[3]={student(1001,18,71),student(1002,19,78),student(1003,20,98)};
	int n;
	cout<<"��������Ҫ��ƽ���ɼ���ѧ����n=";
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
	
