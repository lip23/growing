#include <iostream>
using namespace std;

class basecla          //�Զ���Ļ���baseCla
{				
public:
	virtual double fib(int n)=0;	//����baseCla��˵����һ���麯��fib����Ϊ���麯��
};


class fib1cla:public basecla    //�ɻ���baseCla��������fib1Cla��
{	
public:
	virtual double fib(int n);	//��������˵��ͬһ���麯��fib���򵥱���"����ƽ��"����
};

double fib1cla::fib(int n)
{
	int m;
	if(n==1||n==2)
		m=1;
	else
	{
		m=1;
		int t1=1,t2;
		for(int i=3;i<=n;i++)
		{
			t2=m;
			m=m+t1;
			t1=t2;
		}
	}
	return m;
}
		


class fib2cla:public basecla	//������fib2Cla
 {
public:
	virtual double fib(int n);	//��������˵��ͬһ���麯��fib��ʹ���������ⷨ��
};

double fib2cla::fib(int n)
{
	int *a;
	a=new int[n];
	a[0]=1;
	a[1]=1;
	for(int i=2;i<n;i++)
		a[i]=a[i-1]+a[i-2];
	return a[n-1];
}

		

class fib3cla:public basecla    //������fib2cla
{
	virtual double fib(int n);    //��������˵��ͬһ���麯��fib��ʹ�ú����ݹ�ⷨ��
};

double fib3cla::fib(int n)
{
	if(n==1||n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}


void fun(basecla *p, int n)//�Զ��庯��fun���β�pΪָ������ָ�룬���Ӧʵ�ο�Ϊ��ͬ���������ĵ�ַ��nָ��Ҫ������еĵ�n��
 {
	double d = p->fib(n); 		//����pָ��ֵ�Ĳ�ͬ�������ò�ͬ��������麯��fib
	cout.flags(ios::scientific);
	cout.precision(15);
	cout<<"fib("<<n<<")="<<d<<endl;  
}


int main() 
{
	fib1cla obj1;			                                    //fib1Cla�����obj1
	fib2cla obj2;			                                    //fib2Cla�����obj2
	fib3cla obj3;		                                    	//fib3Cla�����obj3
	cout<<"------------ fib1Cla ------------"<<endl;
	fun(&obj1, 18);  		                                  //�򵥱���"����ƽ��"��ⷽ������fib(1476)
	cout<<"------------ fib2Cla ------------"<<endl;
	fun(&obj2, 18);  		                                  //������ⷽ������fib(888)
	cout<<"------------ fib3Cla ------------"<<endl;
	fun(&obj3, 18); 			                              //�ݹ���ⷽ������fib(35)
	return 0;
}