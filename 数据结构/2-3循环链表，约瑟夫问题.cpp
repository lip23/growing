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
	linknode * del;
	if(cur->link==first)
		cur=first;
	del=cur->link;
	x=del->date;
	cur->link=del->link;
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
		//cout<<"date"<<cur->date<<endl;
		return cur;
	}
	else if(i==0)
		return first;
	else
		return NULL;
}

int main()
{
	int m,n,t,x=0;
	cout<<"please enter m and n "<<endl;
	cin>>m;
	circlelist c;
	c.creat(m);
	c.output();
	cin>>n;
	/*c.remove(1,x);
	cout<<x<<endl;
	c.output();
	c.remove(2,x);
	cout<<x<<endl;
	c.output();
	c.remove(3,x);
	cout<<x<<endl;*/
	for(int i=1;i<m;i++)
	{
		t=i*n-i+1;
		cout<<"t="<<t<<"  ";
		c.remove(t,x);
		cout<<x<<endl;
		c.output();
	}
	//cout<<endl;
	//c.output();
	return 0;
}
	


