#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class student
{
public:
	double sum();
	double average();
	void display();
	void setdate();
private:
	string num;
	string name;
	double score[3];
};

ifstream infile("54.txt",ios::in);

int main()
{
	
	int n;
	student *s;
	double *sum,*ave;
	cout<<"请输入学生的个数："<<endl;
	infile>>n;
	cout<<"n="<<n<<endl;
	s=new student[n];
	sum=new double[n];
	ave=new double[n];
	cout<<setiosflags(ios::left);
	cout<<"请输入学生的注册号、姓名、数学、外语、计算机课程的成绩"<<endl;
	for(int i=0;i<n;i++)
		s[i].setdate();
	cout<<n<<"个学生的数据是:"<<endl;
	cout<<setw(8)<<"注册号"<<setw(8)<<"姓名"<<setw(8)<<"数学"<<setw(8)<<"外语"<<setw(8)<<"计算机"<<endl;
	for(i=0;i<n;i++)
	{
		s[i].display();
		cout<<endl;
		sum[i]=s[i].sum();
		ave[i]=s[i].average();
	}
	int max(double s[],int);
	i=max(sum,n);
	cout<<"总分最高的学生信息是："<<endl;
	cout<<setw(8)<<"注册号"<<setw(8)<<"姓名"<<setw(8)<<"数学"<<setw(8)<<"外语"<<setw(8)<<"计算机"<<setw(8)<<"总分"<<setw(8)<<"平均分"<<endl;
	s[i].display();
	cout<<setw(8)<<sum[i]<<setw(8)<<ave[i]<<endl;
	infile.close();
	return 0;
}

int max(double sum[],int n)
{
	int m=0;
	for(int i=1;i<n;i++)
		if(sum[m]<sum[i])
			m=i;
		return m;
}

void student::setdate()
{
	
	infile>>num>>name;
	for(int i=0;i<3;i++)
		infile>>score[i];
}

void student::display()
{
	cout<<setw(8)<<num<<setw(8)<<name<<setw(8)<<score[0]<<setw(8)<<score[1]<<setw(8)<<score[2];
}

double student::sum()
{
	return double(score[0]+score[1]+score[2]);
}

double student::average()
{
	return double((score[0]+score[1]+score[2])/3);
}

