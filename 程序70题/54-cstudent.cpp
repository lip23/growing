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
	cout<<"������ѧ���ĸ�����"<<endl;
	infile>>n;
	cout<<"n="<<n<<endl;
	s=new student[n];
	sum=new double[n];
	ave=new double[n];
	cout<<setiosflags(ios::left);
	cout<<"������ѧ����ע��š���������ѧ�����������γ̵ĳɼ�"<<endl;
	for(int i=0;i<n;i++)
		s[i].setdate();
	cout<<n<<"��ѧ����������:"<<endl;
	cout<<setw(8)<<"ע���"<<setw(8)<<"����"<<setw(8)<<"��ѧ"<<setw(8)<<"����"<<setw(8)<<"�����"<<endl;
	for(i=0;i<n;i++)
	{
		s[i].display();
		cout<<endl;
		sum[i]=s[i].sum();
		ave[i]=s[i].average();
	}
	int max(double s[],int);
	i=max(sum,n);
	cout<<"�ܷ���ߵ�ѧ����Ϣ�ǣ�"<<endl;
	cout<<setw(8)<<"ע���"<<setw(8)<<"����"<<setw(8)<<"��ѧ"<<setw(8)<<"����"<<setw(8)<<"�����"<<setw(8)<<"�ܷ�"<<setw(8)<<"ƽ����"<<endl;
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

