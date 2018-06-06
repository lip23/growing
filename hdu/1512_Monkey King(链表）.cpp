#include <stdio.h>

class ufset
{
public:
	ufset(int);
	~ufset();
	int cfind(int);
	bool wunion(int,int);
private:
	int* parent;
};

struct node
{
	int data;
	node* link;
	node(int d,node* n=NULL):data(d),link(n){}
};

class queue
{
public:
	queue();
	~queue();
	void qunion(queue&);
	void del(node* &);
	void show();
	void set(int);
	node* getf(){return front;}
	node* front;
};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ufset monkey(n);
		queue* monk=new queue[n];
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			monk[i].set(temp);
		}
		int m;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			int temp1,temp2;
			scanf("%d %d",&temp1,&temp2);
			if(!monkey.wunion(temp1-1,temp2-1))
				printf("%d\n",-1);
			else
				monk[temp1-1].qunion(monk[temp2-1]);

		}
	}
	return 0;
}


queue::queue()
{
	front=new node(1);
}

void queue::set(int n)
{
	node* newnode=new node(n);
	front->link=newnode;
}

queue::~queue()
{
	while(front)
	{
		node* del=front;
		front=front->link;
		delete del;
	}
}

void queue::qunion(queue& q)
{
	node* cur=front;
	node* pos=q.front;
	cur->link->data/=2;
	pos->link->data/=2;
	int t1=cur->link->data;
	int t2=cur->link->data;
	int t3=0,t4=0;
	if(cur->link->link)
		t3=cur->link->link->data;
	if(cur->link->link)
		t4=cur->link->link->data;
	t1=t1>t2?t1:t2;
	t3=t3>t4?t3:t4;
	t1=t1>t3?t1:t3;
	printf("%d\n",t1);
	int temp=cur->data+pos->data;
	if(cur->data>=pos->data)
	{
		pos=pos->link;
		while(pos)
		{
			while(cur->link&&cur->link->data>pos->data)
				cur=cur->link;
			node* newnode=new node(pos->data,cur->link);
			cur->link=newnode;
			pos=pos->link;
		}
		pos=q.front->link;
		front->data=temp;
		q.front->data=temp;
		q.front->link=front->link;
		del(pos);
	}
	else
	{
		cur=cur->link;
		while(cur)
		{
			while(pos->link&&pos->link->data>cur->data)
				pos=pos->link;
			node* newnode=new node(cur->data,pos->link);
			pos->link=newnode;
			cur=cur->link;
		}
		cur=front->link;
		front->data=temp;
		q.front->data=temp;
		front->link=q.front->link;
		del(cur);	
	}

}

void queue::del(node* & cur)
{
	while(cur)
	{
		node* del=cur;
		cur=cur->link;
		delete del;
	}
}

/*bool queue::isempty()
{
	if(front->link)
		return false;
	return true;
}

void queue::show()
{
	message* cur=front->link;
	cout<<"show:";
	while(cur)
	{
		cout<<cur->name<<' '<<cur->par;
		cur=cur->link;
	}
	cout<<endl;
}*/



ufset::ufset(int n)
{
	parent=new int[n];
	for(int i=0;i<n;i++)
		parent[i]=-1;
}




ufset::~ufset()
{
	delete []parent;
}

int ufset::cfind(int n)
{
	for(int r=n;parent[r]>=0;r=parent[r]);
	while(parent[n]>=0)
	{
		int j=parent[n];
		parent[n]=r;
		n=j;
	}
	return r;
}

bool ufset::wunion(int r1,int r2)
{
	int root1=cfind(r1);
	int root2=cfind(r2);
	if(root1==root2)
		return false;
	int temp=parent[root1]+parent[root2];
	if(parent[root1]<parent[root2])
	{
		parent[root2]=root1;
		parent[root1]=temp;
	}
	else
	{
		parent[root1]=root2;
		parent[root2]=temp;
	}
	return true;
}