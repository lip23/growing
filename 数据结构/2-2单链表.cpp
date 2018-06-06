#include <iostream>
#include <iomanip>
using namespace std;

struct linknode
{
	int date;
	linknode * link;
	linknode(linknode*p=NULL){link=p;}
	linknode(const int &d,linknode*p=NULL):link(p),date(d){};
};

class linklist
{
private:
	linknode * first;
public:
	linklist();
	linklist(const int & x);
	linklist(linklist & l);
	~linklist(){makeempty();}
	void makeempty();
	int length()const;
	linknode* gethead()const {return first;}
	linknode* search(int x);
	linknode* locate(int i);
	bool getdate(int i,int &x);
	void setdate(int i,int& x);
	bool insert(int i,int & x);
	bool remove(int i,int & x);
	bool isempty()const;
	bool isfull()const;
	void sort();
	void input();
	void output();
	void suiji();
};

linklist::linklist()
{
	first=new linknode;
	first->link=NULL;
}

linklist::linklist(const int & x)
{
	first=new linknode(x);
}

int linklist::length()const
{
	linknode * cur=first;
	for(int i=0;cur->link;i++)
		cur=cur->link;
	return i;
}

linknode* linklist::locate(int i)                                          //定位到第i个位置
{
	linknode * cur=first;
	for(int j=0;j<i;j++)
	{
		cur=cur->link;
		if(cur==NULL)
		{
			cout<<" date erro "<<endl;
			return NULL;
			exit(1);
		}
	}
	return cur;
}

linknode* linklist::search(int x)
{
	linknode * cur=first;
	while(cur->link)
	{
		if(cur->date==x)
			return cur;
	}
	return NULL;
}


void linklist::setdate(int i,int& x)                               //修改元素值
{
	linknode * cur;
	cur=locate(i);
	cur->date=x;
}


bool linklist::getdate(int i,int &x)                              //取第i个元素
{
	linknode * cur;
	if(locate(i))
	{
		cur=locate(i);
	    x=cur->date;
	    return true;
	}
	return false;
}

bool linklist::insert(int i,int & x)                            //插入元素
{
	linknode * cur;
	cur=locate(i-1);
	if(cur)
	{
		linknode * newnode;
		newnode=new linknode(x);
		newnode->link=cur->link;
		cur->link=newnode;
		return true;
	}
	else
		return false;
}
	
bool linklist::remove(int i,int & x)                           //删除元素
{
	linknode * cur;
	cur=locate(i-1);
	if(cur)
	{
		linknode * del;
		del=cur->link;
		cur->link=del->link;
		x=del->date;
		delete del;
		return true;
	}
	else
		return false;
}


bool linklist::isempty()const
{
	if(first->link==NULL)
		return true;
	else
		return false;
}

bool linklist::isfull()const
{

	return false;
}


void linklist::sort()
{
	linknode * cur1=first;
	linknode * cur2;
	int temp;
	int l=length();
	for(int i=0;i<l;i++)
	{
		cur1=cur1->link;
		cur2=cur1;
		for(int j=i+1;j<l;j++)
		{
			cur2=cur2->link;
			if(cur1->date>cur2->date)
			{
				temp=cur1->date;
				cur1->date=cur2->date;
				cur2->date=temp;
			}
		}
	}
}


void linklist::input()
{
	cout<<"请输入你要输入节点的个数：";
	int n;
	cin>>n;
	cout<<"请输入寻找输入方法：a 前插法， b 后插法";
	char p;
	cin>>p;
	while(p!='a'&&p!='b')
	{
		cout<<"您输入的操作有误，请重新输入：";
		cin>>p;
	}
	linknode * cur=first;
	linknode * newnode;
	cout<<"请输入您要输入的数据："<<endl;
	if(p=='b')
	{
		for(int i=0;i<n;i++)
		{
			newnode=new linknode;
		    cin>>newnode->date;
		    newnode->link=cur->link;
		    cur->link=newnode;
		    cur=newnode;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			newnode=new linknode;
		    cin>>newnode->date;
		    newnode->link=cur->link;
		    cur->link=newnode;
		}
	}
}


void linklist::output()
{
	if(isempty())
		cout<<"该单链表已空"<<endl;
	else
	{
		linknode* cur;
	    cur=first;
	    int l=length();
	    for(int i=1;i<=l;i++)
			cout<<setw(3)<<'['<<i<<']';
	    cout<<endl;
	    while(cur->link)
		{
			cur=cur->link;
		    cout<<setw(5)<<cur->date;
		}
	    cout<<endl;
	}
}

void linklist::suiji()
{
	cout<<"请输入你要输入节点的个数：";
	int n;
	cin>>n;
	linknode * cur=first;
	linknode * newnode;
	for(int i=0;i<n;i++)
	{
		newnode=new linknode;
		newnode->date=rand()%100+10;
		newnode->link=cur->link;
		cur->link=newnode;
	}
}

void linklist::makeempty()                                         //将单链表置空
{
	linknode * cur;
	while(first->link)
	{
		cur=first;
		first=cur->link;
		delete cur;
	}
}

void show()
{
		cout<<"///////////////////////////////////////////////////////////////////////"<<endl;
		cout<<"请输入您接下来要执行的操作：";
}

int main()
{
	cout<<"***************************单链表的基本操作***************************"<<endl;
	cout<<setw(8)<<" "<<"1,初始化一个单链表"<<endl;
	cout<<setw(8)<<" "<<"2,输出单链中的元素"<<endl;
	cout<<setw(8)<<" "<<"3,在第i个元素之前插入一个元素"<<endl;
	cout<<setw(8)<<" "<<"4,取第i个元素的值"<<endl;
	cout<<setw(8)<<" "<<"5,删除第i个元素"<<endl;
	cout<<setw(8)<<" "<<"6,判断单链表是否为满"<<endl;
	cout<<setw(8)<<" "<<"7,判断单链表是否为空"<<endl;
    cout<<setw(8)<<" "<<"8,随机生成单链表(元素为0--99之间)"<<endl;
	cout<<setw(8)<<" "<<"9,对单链表进行排序"<<endl;
	cout<<setw(8)<<" "<<"10,修改第i个元素的值"<<endl;
	cout<<setw(8)<<" "<<"11,取第i个元素的值"<<endl;
	cout<<setw(8)<<" "<<"12,将单链表置空"<<endl;
    cout<<setw(8)<<" "<<"0,终止操作"<<endl;
	linklist l;
	cout<<"************************************************"<<endl;
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
			l.input();
			show();
		}break;
	case 2:
		{
			l.output();
			show();
		}break;
	case 3: 
		{
			int t,i;
			cout<<"请输入您要插入的元素的位置："<<endl;
			cin>>i;
			cout<<"请输入您要插入的元素："<<endl;
			cin>>t;
			l.insert(i,t);
			show();
		}break;
	case 4: 
		{
			int t,i;
			cout<<"请输入您要取的元素的位置："<<endl;
			cin>>i;
			if(l.getdate(i,t))
				cout<<"位置"<<i<<"的元素为："<<t<<endl;
			show();
		}break;
	case 5: 
		{
			int t,i;
			cout<<"请输入您要删除的元素的位置："<<endl;
			cin>>i;
			if(l.remove(i,t))
				cout<<"您要删除的元素是："<<t<<endl;
			show();
		}break;
	case 6: 
		{
			if(l.isfull())
				cout<<"该单链表为满"<<endl;
			else
				cout<<"该单链表为非满"<<endl;
			show();
		}break;
	case 7:
		{
			if(l.isempty())
				cout<<"该单链表为空"<<endl;
			else
				cout<<"该单链表为非空"<<endl;
			show();
		}break;
	case 8:
		{
			l.suiji();
			show();
		}break;
	case 9:
		{
			l.sort();
			show();
		}break;
	case 10:
		{
			int i,x;
			cout<<"请输入您要修改元素的位置：";
			cin>>i;
			if(i<=l.length())
			{
				cout<<"请输入您要修改的值：";
			    cin>>x;
			    l.setdate(i,x);
			}
			else
				cout<<"date erro"<<endl;
			show();
		}break;
	case 11:
		{
			int i,x;
			cout<<"请输入您要取的元素的位置：";
			cin>>i;
			if(l.getdate(i,x))
				cout<<"该元素的值是："<<x<<endl;
			show();
		}break;
	case 12:
		{
			l.makeempty();
			show();
		}break;
	default:cout<<"您输入的数据有误，请重新输入："<<endl;
	};
	}while(b!=0);
	return 0;
}
