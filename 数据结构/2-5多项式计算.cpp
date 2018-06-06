#include <iostream>
#include <iomanip>
using namespace std;

struct linknode
{
	int exp;
	int coef;
	linknode * link;
	linknode(linknode*p=NULL){link=p;}
	linknode(const int &e,const int &c,linknode*p=NULL):link(p),coef(c),exp(e){};
};

class linklist
{
private:
	linknode * first;
public:
	linklist();
	~linklist();
	void suiji();
	void output();
	void sort();
	void sort2();
	int length()const;
	bool isempty()const;
	void insert(int,int);
	friend void plus(linklist &,linklist &,linklist &);
	friend void cheng(linklist &,linklist &,linklist &);
};

int main()
{
	linklist l1,l2;
	l1.suiji();
	l1.sort();
	l1.output();
	l1.sort2();
	cout<<"排序成功后的序列："<<endl;
	l1.output();
	l2.suiji();
	l2.sort();
	l2.output();
	l2.sort2();
	cout<<"排序成功后的序列："<<endl;
	l2.output();
	linklist l;
	plus(l1,l2,l);
	cout<<"多项式1和2的和是："<<endl;
	l.output();
	linklist l3;
	cheng(l1,l2,l3);
	l3.sort();
	l3.sort2();
	cout<<"多项式1和2的乘积是："<<endl;
	l3.output();
	return 0;
}

void cheng(linklist &l1,linklist &l2,linklist &l)
{
	linknode * cur1=l1.first->link;
	linknode * cur2=l2.first->link;
	while(cur1)
	{
		while(cur2)
		{
			l.insert(cur1->coef*cur2->coef,cur1->exp+cur2->exp);
			cur2=cur2->link;
		}
		cur1=cur1->link;
	}
}

linklist::~linklist()
{
	linknode * del;
	while(first)
	{
		del=first;
		first=first->link;
		delete del;
	}
	cout<<"删除成功"<<endl;
}

void linklist::suiji()
{
	cout<<"请输入你要创建的多项式的项数：";
	int n;
	cin>>n;
	linknode * cur=first;
	linknode * newnode;
	for(int i=0;i<n;i++)
	{
		newnode=new linknode;
		newnode->exp=rand()%10;
		newnode->coef=rand()%100+1;
		newnode->link=cur->link;
		cur->link=newnode;
	}
}

void linklist::output()
{
	if(isempty())
		cout<<"该单链表已空"<<endl;
	else
	{
		linknode* cur;
	    cur=first->link;
		while(cur)
		{
			cout<<cur->coef<<"X^"<<cur->exp<<'+';
			cur=cur->link;
		}
		cout<<'\b'<<' ';
		cout<<endl;
	}
}

int linklist::length()const
{
	linknode * cur=first;
	for(int i=0;cur->link;i++)
		cur=cur->link;
	return i;
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
			if(cur1->exp>cur2->exp)
			{
				temp=cur1->exp;
				cur1->exp=cur2->exp;
				cur2->exp=temp;
			}
		}
	}
}

linklist::linklist()
{
	first=new linknode;
	first->link=NULL;
}

bool linklist::isempty()const
{
	if(first->link==NULL)
		return true;
	else
		return false;
}


void linklist::insert(int c,int e)
{
	linknode * cur=first;
	while(cur->link)
		cur=cur->link;
	linknode * newnode;
	newnode=new linknode;
	newnode->exp=e;
	newnode->coef=c;
	newnode->link=cur->link;
	cur->link=newnode;
}

void plus (linklist & c1,linklist & c2, linklist & c)
{
	linknode * cur1=c1.first->link;
	linknode * cur2=c2.first->link;
	while(cur1&&cur2)
	{
		if(cur1->exp<cur2->exp)
		{
			c.insert(cur1->coef,cur1->exp);
			cur1=cur1->link;
		}
		else if(cur1->exp==cur2->exp)
		{
			c.insert(cur1->coef+cur2->coef,cur1->exp);
			cur1=cur1->link;
		    cur2=cur2->link;
		}
		else
		{
		    c.insert(cur2->coef,cur2->exp);
			cur2=cur2->link;
		}
	}
	while(cur1)
	{
		c.insert(cur1->coef,cur1->exp);
		cur1=cur1->link;
	}
	while(cur2)
	{
		c.insert(cur2->coef,cur2->exp);
		cur2=cur2->link;
	}
}

void linklist::sort2()
{
	linknode * cur=first->link;
	while(cur->link)
	{
		while(cur->exp==cur->link->exp)
		{
			linknode *del=cur->link;
			cur->coef=cur->coef+cur->link->coef;
			cur->link=del->link;
			delete del;
		}
		cur=cur->link;
	}
}






