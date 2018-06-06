#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class T>

struct linknode
{
	T date;
	linknode * link;
};

template <class T>

class linkstack
{
public:
	linkstack();
	~linkstack();
	void push(T&);
	bool pop(T&);
	bool gettop(T&)const;
	bool isempty()const;
	int getsize()const;
	void makeempty();
	void output();
private:
	linknode<T> * top;
};

int main()
{
	linkstack<char> s1,s2;
	linkstack<string>s3,s4;
	string c1;
	cin>>c1;
	int i=0;
	while(c1[i])
	{
		do
		{
			s1.push(c1[i]);
			i++;
		}while(c1[i]&&c1[i]!='+'&&c1[i]!='-'&&c1[i]!='*'&&c1[i]!='/');
		int l=s1.getsize();
		string t="0000000000";
		char x;
		for(int j=l-1;j>=0;j--)
		{
			if(s1.pop(x))
				t[j]=x;
		}
		t[l]='\0';
		s3.push(t);
		if(c1[i]=='+'||c1[i]=='-'||c1[i]=='*'||c1[i]=='/')
		{
			char y;
			if(s2.gettop(y))
			{
				if((c1[i]=='+'||c1[i]=='-')&&(y=='*'||y=='/'))
				{
					while(s2.pop(y))
					{
						string t="0";
						t[0]=y;
						t[1]='\0';
						s3.push(t);
					}
				}
				else if((c1[i]=='+'||c1[i]=='-')&&(y=='+'||y=='-'))
				{
					while(s2.pop(y))
					{
						string t="0";
						t[0]=y;
						t[1]='\0';
						s3.push(t);
					}
				}
				else if((c1[i]=='/'||c1[i]=='*')&&(y=='*'||y=='/'))
				{
					while(s2.pop(y))
					{
						string t="0";
						t[0]=y;
						t[1]='\0';
						s3.push(t);
					}
				}
				s2.push(c1[i]);
				i++;
			}
			else
			{
				s2.push(c1[i]);
				i++;
			}
		}
	}
	char y;
	while(s2.pop(y))
	{
		string t="0";
		t[0]=y;
		t[1]='\0';
		s3.push(t);
	}
	//s3.output();
	string temp;
	while(s3.pop(temp))
		s4.push(temp);
	s4.output();
	linkstack<double> s5;
	while(s4.pop(temp))
	{
		if(temp!="+"&&temp!="-"&&temp!="*"&&temp!="/")
		{
			double temp1=0,temp0=0;
			for(int i=0;temp[i]&&temp[i]!='.';i++)
				temp1=temp1*10+temp[i]-48;
			//cout<<"i="<<i<<endl;
			if(temp[i]=='.')
				for(i=i+1;temp[i];i++)
					temp0=temp0/10+temp[i]-48;
			temp1=temp1+temp0/10;
			//cout<<"temp1="<<temp1<<endl;
			s5.push(temp1);
		}
		else
		{
			double temp1,temp2,temp3;
			s5.pop(temp2);
			s5.pop(temp1);
			if(temp=="+")
			{
				temp3=temp1+temp2;
				s5.push(temp3);
			}
			else if(temp=="-")
			{
				temp3=temp1-temp2;
				s5.push(temp3);
			}
			else if(temp=="*")
			{
				temp3=temp2*temp1;
				s5.push(temp3);
			}
			else if(temp=="/")
			{
				temp3=temp1/temp2;
				s5.push(temp3);
			}
		}
	}
	double result;
	s5.pop(result);
	cout<<result<<endl;
	return 0;
}

template <class T>

void linkstack<T>::output()
{
	linknode<T> * cur=top->link;
	while(cur)
	{
		cout<<cur->date<<"  ";
		cur=cur->link;
	}
	cout<<endl;
}

template <class T>

linkstack<T>::linkstack()
{
	top=new linknode<T>;
	top->link=NULL;
	cout<<"栈初始化成功"<<endl;
}

template <class T>

linkstack<T>::~linkstack()
{
	linknode<T> * del=top;
	while(top)
	{
		top=top->link;
		delete del;
		del=top;
	}
	cout<<"栈删除成功"<<endl;
}

template <class T>

void linkstack<T>::push(T & x)
{
	linknode<T> * newnode;
	newnode=new linknode<T>;
	newnode->date=x;
	newnode->link=top->link;
	top->link=newnode;
}

template <class T>

bool linkstack<T>::pop(T & x)
{
	if(top->link)
	{
		x=top->link->date;
		linknode<T> * del=top->link;
		top->link=del->link;
		delete del;
		return true;
	}
	return false;
}

template <class T>

bool linkstack<T>::gettop(T& x)const
{
	if(top->link)
	{
		x=top->link->date;
		return true;
	}
	return false;
}

template <class T>

bool linkstack<T>::isempty()const
{
	if(top->link)
		return false;
	return true;
}

template <class T>
	
int linkstack<T>::getsize()const
{
	linknode<T> * cur=top->link;
	int i=0;
	while(cur)
	{
		i++;
		cur=cur->link;
	}
	return i;
}

template <class T>
	
void linkstack<T>::makeempty()
{
	linknode<T> * cur;
	while(top->link)
	{
		cur=top->link;
		top->link=cur->link;
		delete cur;
	}
}