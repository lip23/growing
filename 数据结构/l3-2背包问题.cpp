#include <iostream>
#include <iomanip>
using namespace std;

class stack
{
public:
	stack(int);
	~stack();
	void push(int);
	int pop();
	int gettop();
	int length();
	void display(int*);
private:
	int * e;
	int size;
	int top;
};

int main()
{
	int* set(int&);
	void bianjie(int&,int&,int*,int);
	int min,max;
	int * m;
	int t;
	m=set(t);
	int w=0,i=0,s;
	bianjie(min,max,m,t);
	cout<<"�����ĳ��ط�Χ�ǣ�"<<min<<"------"<<max<<endl;
	do
	{
		cout<<"�����뱳���ܳ��ܵ�����S��";
	    cin>>s;
	    if(s>max)
			cout<<"����̫�ᣬ���ܰѱ���װ��"<<endl;
	    if(s<min)
		    cout<<"����̫�أ����ܷ��뱳��"<<endl;
	}while(s<min||s>max);
	stack p(t);
	while(w<s)
	{
		w=w+m[i];
		p.push(i);
		i++;
		if(w==s)
		{
			p.display(m);
			break;
		}
		if(p.length()==1&&w>s)
		{
			cout<<"���ܰѱ���װ��"<<endl;
			break;
		}
		if(w>s)
		{
			for(int k=0;k<2;k++)
			{
				i=p.pop();
			    w=w-m[i];
			}
			i++;
		}
		if(p.gettop()==t&&w<s)
		{
			int temp1=p.pop();
			w=w-m[temp1];
			int k=0;
			do
			{
				k++;
				i=p.pop();
				w=w-m[i];
			}while(temp1==i+k&&p.length()>0);
			if(p.length()==0&&temp1==i+k)
			{
				cout<<"22222���ܰѱ���װ��"<<endl;
			    break;
			}
			i++;
		}
		//p.display(m);
	}
	return 0;
}

int* set(int& b)
{
	int* n;
	int t;
	cout<<"����������ĸ�����";
	cin>>t;
	b=t;
	n=new int[t];
	for(int i=0;i<t;i++)
		n[i]=rand()%100+5;
	void sort(int*,int);
	sort(n,t);
	void show(int*,int);
	show(n,t);
	return n;
}

void show(int* n,int t)
{
	cout<<"������ɵ�"<<t<<"������������ǣ�"<<endl;
	for(int i=0;i<t;i++)
		cout<<n[i]<<"  ";
	cout<<endl;
}

void sort(int * m,int t)
{
	for(int i=0;i<t;i++)
	{
		int k=i,temp;
		for(int j=i+1;j<t;j++)
			if(m[k]>m[j])
				k=j;
		temp=m[i];
		m[i]=m[k];
		m[k]=temp;
	}
}

stack::stack(int b)
{
	e=new int[b];
	top=0;
	size=b;
}

stack::~stack()
{
	delete [] e;
	cout<<"�����ɹ�"<<endl;
}

void stack::push(int x)
{
	e[top]=x;
	top++;
}

int stack::pop()
{
	top--;
	return e[top];
}

int stack::gettop()
{
	return e[top-1];
}

int stack::length()
{
	return top;
}

void stack::display(int* m)
{
	for(int i=0;i<top;i++)
		cout<<setw(5)<<e[i];
	cout<<endl;
	for(i=0;i<top;i++)
		cout<<setw(5)<<m[e[i]];
	cout<<endl;
}

void bianjie(int& min,int& max,int* m,int t)
{
	min=m[0];
	max=0;
	for(int i=0;i<t;i++)
		max=max+m[i];
}




	