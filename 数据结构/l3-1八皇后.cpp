#include <iostream>
#include <iomanip>
using namespace std;

class stack
{
public:
	stack();
	void copy(stack s);
	~stack();
	void push(int);
	int pop();
	int length();
	void display();
private:
	int st[8];
	int top;
};

void stack::copy(stack s)
{
	top=s.top;
	for(int i=0;i<top;i++)
		st[i]=s.st[i];
}

stack::stack()
{
	top=0;
}

stack::~stack()
{
	//cout<<"析构成功"<<endl;
}

void stack::display()
{
	for(int j=0;j<top;j++)
		cout<<st[j]<<"  ";
	cout<<endl;
	//cout<<"******************************"<<endl;
}

void stack::push(int t)
{
	st[top]=t;
	top++;
}

int stack::pop()
{
	top--;
	return st[top];
}

int stack::length()
{
	return top;
}


int main()
{
	char a[8][8];
	void set(char b[][8]);
	void show(char b[][8]);
	void quen(char b[][8],int,int,char);
	set(a);
	stack s;
	int c=0;
	int i=0;
	for(;i<8;i++)
	{
		int l=s.length();
		if(a[l][i]!='+')
		{
			quen(a,l,i,'+');
			s.push(i);
			i=-1;//因为在for循环中有i++，所以这这里i应该设为-1，而不是1；
		}
		if(i==7&&a[l][i]=='+'||s.length()==8)
		{
			if(s.length()==8)
			{
				c++;
				//show(a);
				s.display();
				cout<<"count="<<c<<endl;
			}
			do
			{
				int t=s.pop();
			    l=s.length();
			    quen(a,l,t,'1');
			    stack t1;
			    t1.copy(s);
			    int tl;
				int ti;
			    while(t1.length()>0)
				{
					ti=t1.pop();
				    tl=t1.length();
				    quen(a,tl,ti,'+');
				}
				i=t;//同样是因为在for循环中有i++，所以此处让i=t；让后i++；i就变成了t+1；
			}while(i==7&&s.length()!=0);
		}
		if(i==7&&s.length()==0)
			break;
	}
	return 0;
}

void quen(char b[8][8],int m,int n,char x)
{
	b[m][n]='Q';
	if(x=='1')
		b[m][n]='1';
	for(int i=1;i<8;i++)
	{
		if(m+i<8)
			b[m+i][n]=x;
		if(m-i>=0)
			b[m-i][n]=x;
		if(n+i<8)
			b[m][n+i]=x;
		if(n-i>=0)
			b[m][n-i]=x;
		if(m+i<8&&n+i<8)
			b[m+i][n+i]=x;
		if(m-i>=0&&n-i>=0)
			b[m-i][n-i]=x;
		if(m+i<8&&n-i>=0)
			b[m+i][n-i]=x;
		if(m-i>=0&&n+i<8)
			b[m-i][n+i]=x;
	}
}


void set(char b[8][8])
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			b[i][j]='1';
}


void show(char b[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<b[i][j]<<"  ";
		cout<<endl;
	
	}	
	cout<<"******************************"<<endl;
}