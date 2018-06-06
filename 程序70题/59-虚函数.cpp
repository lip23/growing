#include <iostream>
using namespace std;

class basecla          //自定义的基类baseCla
{				
public:
	virtual double fib(int n)=0;	//基类baseCla中说明了一个虚函数fib，且为纯虚函数
};


class fib1cla:public basecla    //由基类baseCla派生出的fib1Cla类
{	
public:
	virtual double fib(int n);	//派生类中说明同一个虚函数fib（简单变量"数据平移"法）
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
		


class fib2cla:public basecla	//派生类fib2Cla
 {
public:
	virtual double fib(int n);	//派生类中说明同一个虚函数fib（使用数组的求解法）
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

		

class fib3cla:public basecla    //派生类fib2cla
{
	virtual double fib(int n);    //派生类中说明同一个虚函数fib（使用函数递归解法）
};

double fib3cla::fib(int n)
{
	if(n==1||n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}


void fun(basecla *p, int n)//自定义函数fun，形参p为指向基类的指针，其对应实参可为不同派生类对象的地址；n指明要求出数列的第n项
 {
	double d = p->fib(n); 		//根据p指针值的不同，将调用不同派生类的虚函数fib
	cout.flags(ios::scientific);
	cout.precision(15);
	cout<<"fib("<<n<<")="<<d<<endl;  
}


int main() 
{
	fib1cla obj1;			                                    //fib1Cla类对象obj1
	fib2cla obj2;			                                    //fib2Cla类对象obj2
	fib3cla obj3;		                                    	//fib3Cla类对象obj3
	cout<<"------------ fib1Cla ------------"<<endl;
	fun(&obj1, 18);  		                                  //简单变量"数据平移"求解方法，求fib(1476)
	cout<<"------------ fib2Cla ------------"<<endl;
	fun(&obj2, 18);  		                                  //数组求解方法，求fib(888)
	cout<<"------------ fib3Cla ------------"<<endl;
	fun(&obj3, 18); 			                              //递归求解方法，求fib(35)
	return 0;
}