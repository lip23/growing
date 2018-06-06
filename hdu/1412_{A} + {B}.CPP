#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

class list
{
public:
	list();
	~list();
	void inlist(int&);
	void show();
private:
	node* front;
};
	

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		list l;
		for(int i=0;i<n+m;i++)
		{
			int temp;
			cin>>temp;
			l.inlist(temp);
		}
		l.show();
	}
	return 0;
}

list::list()
{
	front=new node;
	front->link=NULL;
}

list::~list()
{
	while(front)
	{
		node* del=front;
		front=front->link;
		delete del;
		//cout<<"deleting"<<endl;
	}
}

void list::inlist(int& d)
{
	//cout<<"inlist"<<endl;
	node* cur=front;
	while(cur->link&&d>cur->link->data)
		cur=cur->link;
	if(cur->link==NULL||d!=cur->link->data)
	{
		//cout<<"newnode"<<endl;
		node* newnode=new node;
		newnode->data=d;
		newnode->link=cur->link;
		cur->link=newnode;
	}
}

void list::show()
{
	//cout<<"show"<<endl;
	node* cur=front->link;
	while(cur)
	{
		cout<<cur->data;
		cur=cur->link;
		if(cur)
			cout<<' ';
	}
	cout<<endl;
}