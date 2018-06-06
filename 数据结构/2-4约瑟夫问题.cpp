
#include <iostream>
#include <iomanip>
using namespace std;

struct linknode
{
	int date;
	linknode * link;
};

class circlelist
{
private:
	linknode * first;
	linknode * last;
public:
	circlelist();
	void creat(int);
	void output();
	linknode * locate(int i);
	bool remove(int i,int & x);
};

circlelist::circlelist()
{
	first=new linknode;
	first->link=first;
	cout<<"creat succeed!"<<endl;
}

void circlelist::creat(int m)
{
	linknode * cur=first;
	linknode * newnode;
	for(int i=1;i<=m;i++)
	{
		newnode=new linknode;
		newnode->date=i;
		cur->link=newnode;
		cur=newnode;
	}
	cur->link=first;
	last=cur;
}

void circlelist::output()
{
	linknode * cur=first->link;
	while(cur!=first)
	{
		cout<<cur->date<<"  ";
		cur=cur->link;
	}
	cout<<endl;
}

bool circlelist::remove(int i,int & x)
{

	if(i<1)
		return false;
	linknode * cur=locate(i-1);	
	linknode * del=cur->link;
	if(cur==last)
		del=first->link;
	if(cur==first)
		cur->link=del->link;
	else if(cur->link==last)
	{
		last=cur;
		last->link=first;
	}
	else
	{
		last->link=first->link;
		first->link=del->link;	
		cur->link=first;
		last=cur;
	}
	x=del->date;
	delete del;
	return true;
}

linknode * circlelist::locate(int i)
{
	linknode * cur=first;
	if(i>0)
	{
		for(int j=0;j<i;j++)
		{
			cur=cur->link;
			if(cur==first)
				cur=cur->link;
		}
	return cur;
	}
	else if(i==0)
		return first;
	else
		return NULL;
}

int main()
{
	int m,x;
	int n;
	cout<<"请输入人数m:"<<endl;
	cin>>m;
	circlelist c;
	c.creat(m);
	c.output();
	cout<<"请输入报数数字n:"<<endl;
	cin>>n;
	cout<<endl;
	for(int i=1;i<m;i++)
	{
		c.remove(n,x);
		cout<<"第"<<i<<"次:"<<endl;
		cout<<"删除的元素是："<<x<<endl;
		cout<<"剩余的人有:"<<endl;
		c.output();
	}
	return 0;
}
