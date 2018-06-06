#include <iostream>
#include <iomanip>
using namespace std;

struct linknode
{
	int date;
	linknode * link;
};

void show()
{
	cout<<"��������������Ҫִ�еĲ���";
}

class linkstack
{
public:
	linkstack();
	~linkstack();
	void push(int&);
	bool pop(int&);
	bool gettop(int&)const;
	bool isempty()const;
	int getsize()const;
	void makeempty();
	void output();
private:
	linknode * top;
};

int main()
{
	cout<<"***************************��ջ�Ļ�������***************************"<<endl;
	cout<<setw(8)<<" "<<"1,��ջ"<<endl;
	cout<<setw(8)<<" "<<"2,��ջ"<<endl;
	cout<<setw(8)<<" "<<"3,���ջ��Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"4,��ջ�ÿ�"<<endl;
	cout<<setw(8)<<" "<<"5,�ж�ջ��"<<endl;
	cout<<setw(8)<<" "<<"6,���ջ�Ĵ�С"<<endl;
	cout<<setw(8)<<" "<<"7,���ջ��Ԫ��"<<endl;
    cout<<setw(8)<<" "<<"0,��ֹ����"<<endl;
	cout<<"************************************************"<<endl;
	linkstack s;
	int b;	
	cout<<"��������Ҫִ�еĲ�����";
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"������ֹ"<<endl;break;
	case 1: 
		{
			cout<<"��������Ҫ��ջ��Ԫ�أ�";
			int x;
			cin>>x;
			s.push(x);
			show();
		}break;
	case 2:
		{
			int x;
			if(s.pop(x))
				cout<<"��ջ��Ԫ���ǣ�"<<x<<endl;
			else
				cout<<"����ʧ��"<<endl;
			show();
		}break;
	case 3: 
		{
			int x;
			if(s.gettop(x))
				cout<<"ջ��Ԫ���ǣ�"<<x<<endl;
			else
				cout<<"����ʧ��"<<endl;
			show();
		}break;
	case 4: 
		{
			s.makeempty();
			show();
		}break;
	case 5: 
		{
			if(s.isempty())
				cout<<"�õ�����Ϊ��"<<endl;
			else
				cout<<"�õ�����Ϊ�ǿ�"<<endl;
			show();
		}break;
	case 6: 
		{
			int l=s.getsize();
			cout<<"��ջ�Ĵ�С�ǣ�"<<l<<endl;
			show();
		}break;
	case 7:
		{
			s.output();
			show();
		}break;
	default:cout<<"������������������������룺"<<endl;
	};
	}while(b!=0);
	return 0;
}

void linkstack::output()
{
	linknode * cur=top->link;
	while(cur)
	{
		cout<<setw(5)<<cur->date;
		cur=cur->link;
	}
	cout<<endl;
}


linkstack::linkstack()
{
	top=new linknode;
	top->link=NULL;
	cout<<"ջ��ʼ���ɹ�"<<endl;
}

linkstack::~linkstack()
{
	linknode * del=top;
	while(top)
	{
		top=top->link;
		delete del;
		del=top;
	}
	cout<<"ջɾ���ɹ�"<<endl;
}

void linkstack::push(int & x)
{
	linknode * newnode;
	newnode=new linknode;
	newnode->date=x;
	newnode->link=top->link;
	top->link=newnode;
}

bool linkstack::pop(int & x)
{
	if(top->link)
	{
		x=top->link->date;
		linknode * del=top->link;
		top->link=del->link;
		delete del;
		return true;
	}
	return false;
}

bool linkstack::gettop(int& x)const
{
	if(top->link)
	{
		x=top->link->date;
		return true;
	}
	return false;
}

bool linkstack::isempty()const
{
	if(top->link)
		return false;
	return true;
}
	
int linkstack::getsize()const
{
	linknode * cur=top->link;
	int i=0;
	while(cur)
	{
		i++;
		cur=cur->link;
	}
	return i;
}
	
void linkstack::makeempty()
{
	linknode * cur;
	while(top->link)
	{
		cur=top->link;
		top->link=cur->link;
		delete cur;
	}
}



