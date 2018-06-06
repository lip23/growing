#include <iostream.h>
#include <malloc.h>
typedef struct qnode//构造队列节点的结构体类型
{
	int date;
	struct qnode *next;
}qnode,*linkqnode;


typedef struct     //构造队列的结构体类型
{
	linkqnode front;
	linkqnode rear;
	int size;
}linkqueue;


void initqueue(linkqueue &l)//构造一个空队列
{
	l.front=l.rear=(linkqnode)malloc(sizeof(qnode));
	if(!l.front)
		cout<<"队列初始化失败"<<endl;
	l.front->next=NULL;
	l.size=0;
	cout<<"队列初始化成功"<<endl;
}


void enqueue(linkqueue &l,int e)//插入元素e为l的新的队尾元素
{
	linkqnode p;
	p=(linkqnode)malloc(sizeof(qnode));
	if(!p)
		cout<<"存储分配失败"<<endl;
	p->date=e;
	p->next=NULL;
	l.rear->next=p;
	l.rear=p;
	l.size++;
	cout<<"插入成功"<<endl;
}


void dequeue(linkqueue &l,int &e)//若队列不空，则删除l的对头元素，用e返回其值，
{
	linkqnode p;
	if(l.front==l.rear)
		cout<<"队列为空，终止操作"<<endl;
	p=l.front->next;
	e=p->date;
	l.front->next=p->next;
	if(l.rear==p)
		l.rear=l.front;
	free(p);
	cout<<"队头元素删除成功"<<endl;
	l.size--;
}


void destroyqueue(linkqueue &l)//销毁队列
{
	while(l.front)
	{
		l.rear=l.front->next;
		free(l.front);
		l.front=l.rear;
	}
	cout<<"队列已成功销毁"<<endl;
}


void putout(linkqueue l)//输出当前队列中的元素
{
	linkqnode p;
	p=(linkqnode)malloc(sizeof(qnode));
	p=l.front->next;
	cout<<"当前队列中的元素是"<<endl;
	for(int i=1;i<=l.size;i++)
	{
		cout<<p->date<<"  ";
		p=p->next;
	}
}


	



void main()
{
	linkqueue l;
	char m;
	initqueue(l);
	do
	{
		cout<<endl<<"请选择您要执行的操作：a 元素进队；b 元素出队；c 销毁队列"<<endl;
		cin>>m;
		cout<<endl;
		if(m=='a')
		{
			int e;
			cout<<"请输入您要入队的元素e=  ";
			cin>>e;
			cout<<endl;
			enqueue(l,e);
			putout(l);
		}
		else if(m=='b')
		{
			int e;
			dequeue(l,e);
			putout(l);
		}
		else if(m=='c')
		{
			destroyqueue(l);
		}
		else
		{
			cout<<"您输入的操作有误，请重新输入"<<endl;
			cin>>m;
		}
	}while(m!='c');	
}