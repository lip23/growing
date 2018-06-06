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
	cout<<"请输入您接下来要执行的操作";
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
	cout<<"***************************链栈的基本操作***************************"<<endl;
	cout<<setw(8)<<" "<<"1,进栈"<<endl;
	cout<<setw(8)<<" "<<"2,出栈"<<endl;
	cout<<setw(8)<<" "<<"3,输出栈顶元素"<<endl;
	cout<<setw(8)<<" "<<"4,将栈置空"<<endl;
	cout<<setw(8)<<" "<<"5,判断栈空"<<endl;
	cout<<setw(8)<<" "<<"6,输出栈的大小"<<endl;
	cout<<setw(8)<<" "<<"7,输出栈中元素"<<endl;
    cout<<setw(8)<<" "<<"0,终止操作"<<endl;
	cout<<"************************************************"<<endl;
	linkstack s;
	int b;	
	cout<<"请输入您要执行的操作：";
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"操作终止"<<endl;break;
	case 1: 
		{
			cout<<"请输入您要进栈的元素：";
			int x;
			cin>>x;
			s.push(x);
			show();
		}break;
	case 2:
		{
			int x;
			if(s.pop(x))
				cout<<"出栈的元素是："<<x<<endl;
			else
				cout<<"操作失败"<<endl;
			show();
		}break;
	case 3: 
		{
			int x;
			if(s.gettop(x))
				cout<<"栈顶元素是："<<x<<endl;
			else
				cout<<"操作失败"<<endl;
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
				cout<<"该单链表为空"<<endl;
			else
				cout<<"该单链表为非空"<<endl;
			show();
		}break;
	case 6: 
		{
			int l=s.getsize();
			cout<<"该栈的大小是："<<l<<endl;
			show();
		}break;
	case 7:
		{
			s.output();
			show();
		}break;
	default:cout<<"您输入的数据有误，请重新输入："<<endl;
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
	cout<<"栈初始化成功"<<endl;
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
	cout<<"栈删除成功"<<endl;
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



