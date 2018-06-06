#include <iostream.h>
#include <malloc.h>
typedef struct stack
{
	int date;
	struct stack *next;
}stack,*linkstack;


void creatlinkstack(linkstack &top,int n)//创建一个大小为n的栈
{
	linkstack p;
	top=(linkstack)malloc(sizeof(stack));
	top->next=0;
	for(n;n>0;n--)
	{
		p=(linkstack)malloc(sizeof(stack));
		p->next=top->next;
		top->next=p;
		cin>>(p->date);
	}
}


void pushlinkstack(linkstack top,int n)//输出栈中元素
{
	linkstack q;
	linkstack p;
	q=top;
	for(n;n>0;n--)
	{
		p=q->next;
		q=p;	
		cout<<p->date<<endl;
	}
}


void putlinkstack(linkstack &top)//在插入元素e
{
	linkstack p;
	int e;
	p=(linkstack)malloc(sizeof(stack));
	cout<<"请您输入要插入的元素e=  ";
	cin>>e;
	cout<<endl;
	p->date=e;
	p->next=top->next;
	top->next=p;
}



void dellinkstack(linkstack &top)//删除栈顶元素并用e返回
{
	int e;
	e=top->next->date;
	cout<<"您要删除的栈顶元素是  "<<e<<endl;
	top->next=top->next->next;
}



void toplinkstack(linkstack top)//访问栈顶元素
{
	int e;
	e=top->next->date;
	cout<<"该栈的栈顶元素e=  "<<e<<endl;
}


/*int caozuo( )//选择您要执行的操作
{
	int m;
	cout<<"请选择您要执行的操作 1 插入栈顶元素 2 删除栈顶元素 3访问栈顶元素 4终止操作"<<endl;
	cin>>m;
	return m;
}*/







void main()
{
	int n;//栈的大小
	int m;//执行的操作
	linkstack top;
	cout<<"请您输入要创建的栈的大小n=  ";
	cin>>n;
	cout<<endl;
	cout<<"请您输入栈中的元素"<<endl;
	creatlinkstack(top,n);
	cout<<"您创建的栈的序列是"<<endl;
	pushlinkstack(top,n);
	cout<<"请选择您要执行的操作 1 插入栈顶元素 2 删除栈顶元素 3访问栈顶元素 4终止操作"<<endl;
	cin>>m;
	while(m<1||m>4)
	{
		cout<<"输入的操作有误，请重新输入m=  ";
		cin>>m;
		cout<<endl;
	}
	while(m!=4)
	{
		
		switch(m)
		{
		case 1:
			{
				putlinkstack(top);
				n++;
				pushlinkstack(top,n);
			};break;
		case 2:
			{
				dellinkstack(top);
				n--;
				pushlinkstack(top,n);
			};break;
		case 3:
			{
				toplinkstack(top);
			}break;
		}
		cout<<"请选择您要执行的操作 1 插入栈顶元素 2 删除栈顶元素 3访问栈顶元素 4终止操作"<<endl;
		cin>>m;
	}
}











