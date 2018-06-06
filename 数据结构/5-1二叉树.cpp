#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	char date;
	node * lchild;
	node * rchild;
	node()
	{
		lchild=NULL;
		rchild=NULL;
	}
	node(char m):date(m){}
};

class stack
{
public:
	stack();
	void push(node *,int);
	node * pop(int &);
	bool isempty();
private:
	int top;
	int base;
	node * a[50];
	int dic[50];//用dic[i]=1,2来记录a[i]为左子树或右子树
};

class queue
{
public:
	queue();
	~queue();
	void enqueue(node *);
	void dequeue(node * &);
	bool isempty();
private:
	node * date[50];
	int front;
	int rear;
};

class binarytree
{
public:
	binarytree();
	~binarytree( );	
	void fdpro();//非递归先序建立二叉树非递归算法
	void preorder();//先序创建二叉树递归算法函数接口
	void show();//三序遍历+层次遍历二叉树函数接口
	void display();//输出二叉树函数接口
	int deep();//求二叉树的深度的函数接口
	int count();//求二叉树结点个数函数接口
	void deltree();//删除二叉树
private:
	node * roof;
	void deep2(int&,node*,int);//求二叉树的深度
	void dis(node*,int,int,char s[40][79],int);//输出二叉树
	void del(node *);//删除二叉树的所有节点
	void dlr(node * t);//先序遍历二叉树
	void ldr(node * t);//中序遍历二叉树
	void lrd(node * t);//后序遍历二叉树
	void level();//层次遍历二叉树
	void countnode(node * t,int & c);//二叉树结点个数
	void creatbitree(node * & );//先序创建二叉树递归算法
};

int main()
{
	binarytree t;
	t.preorder();
	//t.fdpro();
	t.display();
	cout<<"二叉树的深度是："<<t.deep()<<endl;
	cout<<"二叉树的结点个数是："<<t.count()<<endl;
	for(int i=0;i<4;i++)
		t.show();
	return 0;
}

binarytree::binarytree()
{
	roof=NULL;
}

binarytree::~binarytree( )
{
	del(roof);
	cout<<"析构成功"<<endl;
}

void binarytree::del(node *p)//删除二叉树的所有节点
{
	if(p)
	{
		del(p->lchild);
		del(p->rchild);
		delete p;
	}
}

void binarytree::fdpro()//先序创建二叉树非递归算法
{
	cout<<"请按先序输入二叉树（ #表示空节点 ）："<<endl;
	stack p;
	char m;
	cin>>m;
	if(m!='#')
	{
		roof=new node;
		roof->date=m;
		p.push(roof,1);
		p.push(roof,2);
		do
		{
			cin>>m;
			node * t;
			node * temp;
			int dic;
			if(m=='#')
				temp=p.pop(dic);
			else
			{
				t=new node;
				t->date=m;
				temp=p.pop(dic);
				p.push(t,1);
				p.push(t,2);
				if(dic==1)
					temp->rchild=t;
				else
					temp->lchild=t;
			}
		}while(!p.isempty());
	}
}

void binarytree::preorder()//先序创建二叉树递归算法函数接口
{
	cout<<"请按先序输入二叉树（ #表示空节点 ）："<<endl;
	creatbitree(roof);
}

void binarytree::creatbitree(node * & t)//先序创建二叉树递归算法
{
	char m;
	cin>>m;
	if(m=='#')
		t=NULL;
	else
	{
		t=new node(m);
		//t->date=m;
		creatbitree(t->lchild);
		creatbitree(t->rchild);
	}
}

void binarytree::show()//三序遍历二叉树
{
	cout<<"请选择遍历顺序：1，先序遍历  2，中序遍历  3，后序遍历  4，层次遍历 :";
	int m;
	cin>>m;
	if(m==1)
	{
		cout<<"二叉树的先序遍历：";
		dlr(roof);
	}
	else if(m==2)
	{
		cout<<"二叉树的中序遍历：";
		ldr(roof);
	}
	else if(m==3)
	{
		cout<<"二叉树的后序遍历：";
		lrd(roof);
	}
	else if(m==4)
	{
		cout<<"二叉树的层次遍历：";
		level();
	}
	else
		cout<<"您输入的参数有误";
	cout<<endl;
}

void binarytree::dlr(node * t)//先序遍历二叉树
{
	if(t)
	{
		cout<<t->date;
		dlr(t->lchild);
		dlr(t->rchild);
	}
}

void binarytree::ldr(node*t)//中序遍历二叉树
{
	if(t)
	{
		ldr(t->lchild);
		cout<<t->date;
		ldr(t->rchild);
	}
}

void binarytree::lrd(node*t)//后序遍历二叉树
{
	if(t)
	{
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->date;
	}
}

void binarytree::level()//层次遍历二叉树
{
	queue q;
	node * t=roof;
	do{
		if(t)
		{
			cout<<t->date;
			q.enqueue(t->lchild);
			q.enqueue(t->rchild);
		}
		q.dequeue(t);
	}while(!q.isempty()||t);
}

void binarytree::display()//二叉树输出函数的接口
{
	char s[40][79];
	for(int i=0;i<40;i++)
		for(int k=0;k<79;k++)
			s[i][k]=' ';
	int d=deep();
	if(d==0)
		cout<<"该二叉树为空树"<<endl;
	else if(d==1)
		cout<<"该二叉树只有一个根节点："<<roof->date<<endl;
	else if(d>6)
		cout<<"该二叉树太大无法显示"<<endl;
	else
	{
		int temp=1;
		for(int i=0;i<d-2;i++)
			temp*=2;
		dis(roof,0,39,s,temp);
		cout<<"该二叉树为："<<endl;
		for(i=0;i<temp*2;i++)
		{
			for(int k=0;k<79;k++)
				cout<<s[i][k];
			cout<<endl;
		}
	}
}

void binarytree::dis(node * t,int tx,int ty,char s[40][79],int temp)//二叉树输出
{
	if(t)
	{
		s[tx][ty]=t->date;
	    dis(t->lchild,tx+temp,ty-temp,s,temp/2);
	    dis(t->rchild,tx+temp,ty+temp,s,temp/2);
	}
}

int binarytree::deep()//求二叉树深度函数接口
{
    int d=0;
	int tj=0;
	deep2(d,roof,tj);
	return d;
}

void binarytree::deep2(int& d,node* t,int tj)//求二叉树深度
{
	if(t)
	{
		int temp=tj+1;
		if(temp>d)
			d=temp;
		deep2(d,t->lchild,temp);
		deep2(d,t->rchild,temp);
	}
}

int binarytree::count()//求二叉树结点个数函数接口
{
	int c=0;
	countnode(roof,c);
	return c;
}

void binarytree::countnode(node * t,int & c)//二叉树结点个数
{
	if(t)
	{
		c++;
		countnode(t->lchild,c);
		countnode(t->rchild,c);
	}
}

void binarytree::deltree()//删除二叉树
{
	del(roof);
	cout<<"二叉树删除成功"<<endl;
}

///////////////////////栈的成员函数////////////////////////

stack::stack()
{
	base=0;
	top=0;
}

void stack::push(node * p,int d)
{
	a[top]=p;
	dic[top]=d;
	top++;
}

node * stack::pop(int & d)
{
	if(top==0)
	{
		cout<<"栈空"<<endl;
		return NULL;
	}
	top--;
	d=dic[top];
	return a[top];
}

bool stack::isempty()
{
	if(top==0)
		return true;
	return false;
}

/////////////////////////队列的成员函数////////////////////////

queue::queue()
{
	front=rear=0;
}

queue::~queue()
{
	front=rear=0;
	//cout<<"队列析构成功"<<endl;
}

void queue::enqueue(node *t)
{
	if(rear==49)
		cout<<"队列已满，操作错误"<<endl;
	else
	{
		date[rear]=t;
	    rear++;
	}
}

void queue::dequeue(node * & t)
{
	if(rear==front)
		cout<<"队列已空，操作错误"<<endl;
	else
	{
		t=date[front];
		front++;
	}
}

bool queue::isempty()
{
	if(front==rear)
		return true;
	return false;
}
