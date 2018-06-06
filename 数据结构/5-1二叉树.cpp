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
	int dic[50];//��dic[i]=1,2����¼a[i]Ϊ��������������
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
	void fdpro();//�ǵݹ��������������ǵݹ��㷨
	void preorder();//���򴴽��������ݹ��㷨�����ӿ�
	void show();//�������+��α��������������ӿ�
	void display();//��������������ӿ�
	int deep();//�����������ȵĺ����ӿ�
	int count();//������������������ӿ�
	void deltree();//ɾ��������
private:
	node * roof;
	void deep2(int&,node*,int);//������������
	void dis(node*,int,int,char s[40][79],int);//���������
	void del(node *);//ɾ�������������нڵ�
	void dlr(node * t);//�������������
	void ldr(node * t);//�������������
	void lrd(node * t);//�������������
	void level();//��α���������
	void countnode(node * t,int & c);//������������
	void creatbitree(node * & );//���򴴽��������ݹ��㷨
};

int main()
{
	binarytree t;
	t.preorder();
	//t.fdpro();
	t.display();
	cout<<"������������ǣ�"<<t.deep()<<endl;
	cout<<"�������Ľ������ǣ�"<<t.count()<<endl;
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
	cout<<"�����ɹ�"<<endl;
}

void binarytree::del(node *p)//ɾ�������������нڵ�
{
	if(p)
	{
		del(p->lchild);
		del(p->rchild);
		delete p;
	}
}

void binarytree::fdpro()//���򴴽��������ǵݹ��㷨
{
	cout<<"�밴��������������� #��ʾ�սڵ� ����"<<endl;
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

void binarytree::preorder()//���򴴽��������ݹ��㷨�����ӿ�
{
	cout<<"�밴��������������� #��ʾ�սڵ� ����"<<endl;
	creatbitree(roof);
}

void binarytree::creatbitree(node * & t)//���򴴽��������ݹ��㷨
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

void binarytree::show()//�������������
{
	cout<<"��ѡ�����˳��1���������  2���������  3���������  4����α��� :";
	int m;
	cin>>m;
	if(m==1)
	{
		cout<<"�����������������";
		dlr(roof);
	}
	else if(m==2)
	{
		cout<<"�����������������";
		ldr(roof);
	}
	else if(m==3)
	{
		cout<<"�������ĺ��������";
		lrd(roof);
	}
	else if(m==4)
	{
		cout<<"�������Ĳ�α�����";
		level();
	}
	else
		cout<<"������Ĳ�������";
	cout<<endl;
}

void binarytree::dlr(node * t)//�������������
{
	if(t)
	{
		cout<<t->date;
		dlr(t->lchild);
		dlr(t->rchild);
	}
}

void binarytree::ldr(node*t)//�������������
{
	if(t)
	{
		ldr(t->lchild);
		cout<<t->date;
		ldr(t->rchild);
	}
}

void binarytree::lrd(node*t)//�������������
{
	if(t)
	{
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->date;
	}
}

void binarytree::level()//��α���������
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

void binarytree::display()//��������������Ľӿ�
{
	char s[40][79];
	for(int i=0;i<40;i++)
		for(int k=0;k<79;k++)
			s[i][k]=' ';
	int d=deep();
	if(d==0)
		cout<<"�ö�����Ϊ����"<<endl;
	else if(d==1)
		cout<<"�ö�����ֻ��һ�����ڵ㣺"<<roof->date<<endl;
	else if(d>6)
		cout<<"�ö�����̫���޷���ʾ"<<endl;
	else
	{
		int temp=1;
		for(int i=0;i<d-2;i++)
			temp*=2;
		dis(roof,0,39,s,temp);
		cout<<"�ö�����Ϊ��"<<endl;
		for(i=0;i<temp*2;i++)
		{
			for(int k=0;k<79;k++)
				cout<<s[i][k];
			cout<<endl;
		}
	}
}

void binarytree::dis(node * t,int tx,int ty,char s[40][79],int temp)//���������
{
	if(t)
	{
		s[tx][ty]=t->date;
	    dis(t->lchild,tx+temp,ty-temp,s,temp/2);
	    dis(t->rchild,tx+temp,ty+temp,s,temp/2);
	}
}

int binarytree::deep()//���������Ⱥ����ӿ�
{
    int d=0;
	int tj=0;
	deep2(d,roof,tj);
	return d;
}

void binarytree::deep2(int& d,node* t,int tj)//����������
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

int binarytree::count()//������������������ӿ�
{
	int c=0;
	countnode(roof,c);
	return c;
}

void binarytree::countnode(node * t,int & c)//������������
{
	if(t)
	{
		c++;
		countnode(t->lchild,c);
		countnode(t->rchild,c);
	}
}

void binarytree::deltree()//ɾ��������
{
	del(roof);
	cout<<"������ɾ���ɹ�"<<endl;
}

///////////////////////ջ�ĳ�Ա����////////////////////////

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
		cout<<"ջ��"<<endl;
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

/////////////////////////���еĳ�Ա����////////////////////////

queue::queue()
{
	front=rear=0;
}

queue::~queue()
{
	front=rear=0;
	//cout<<"���������ɹ�"<<endl;
}

void queue::enqueue(node *t)
{
	if(rear==49)
		cout<<"������������������"<<endl;
	else
	{
		date[rear]=t;
	    rear++;
	}
}

void queue::dequeue(node * & t)
{
	if(rear==front)
		cout<<"�����ѿգ���������"<<endl;
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
