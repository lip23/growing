#include <iostream.h>
#include <malloc.h>
typedef struct lnode//定义节点类型，元素+指针=节点
{
	int date;//元素类型
	struct lnode *next;//定义指针类型为lnode的指针
}lnode,*linklist;//两个结构体名，第一个定义结构名，第二个定义结构体指针名



void creatlinklist(linklist &l,int n)//创建n个节点的链表，
{
	linklist p;
	l=(linklist)malloc(sizeof(lnode));//malloc函数创建一个元素类型为lnode的linklist（lnode*）指针
	l->next=NULL;
	cout<<"请逆序输入链表的元素"<<endl;
	for(n;n>0;n--)
	{
		p=(linklist)malloc(sizeof(lnode));
		cin>>(p->date);
		p->next=l->next;
		l->next=p;
	}
}



void outlinklist(linklist l,int n)//输出链表
{
	linklist q;
	linklist p;
	p=l->next;
	cout<<"链表的顺序是："<<endl;
	for(int i=n;i>0;i--)
	{
		cout<<p->date<<"  ";
		q=p;
		p=q->next;
	}
	cout<<endl;
}


void pushlinklist(linklist &l,int e,int i,int n)//在链表l的第i位置插入e；
{
	linklist p;
	linklist q;
	p=(linklist)malloc(sizeof(lnode));
	q=l;
	p->date=e;;
	for(i;i>1;i--)
		q=q->next;
    p->next=q->next;
	q->next=p;
}



void dellinklist(linklist &l,int i)//删除第i个元素
{
	linklist p;
	p=l;
	for(i;i>1;i--)
		p=l->next;
	cout<<(p->next->date)<<endl;
	p->next=p->next->next;
	
	//free(p->next);
}


void getlinklist(linklist l,int i)
{
	linklist p;
	p=l->next;
	for(i;i>1;i--)
		p=p->next;
	cout<<(p->date)<<endl;
}



void main()
{
	int n;//链表长度
	int e;
	int i;
	linklist l;
	cout<<"请输入你要创建的链表的大小"<<endl;
	cin>>n;
	creatlinklist(l,n);
	outlinklist(l,n);
	cout<<"请输入您要输入的元素e=  ";
	cin>>e;
	cout<<endl;
	cout<<"请输入您要输入的元素位置i=  ";
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"您输入的位置错误,请重新输入：i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"您要操作的位置i=  "<<i<<endl;
	pushlinklist(l,e,i,n);
	n++;
	outlinklist(l,n);
	cout<<"请输入您要删除元素的位置i=  "<<endl;
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"您输入的位置错误,请重新输入：i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"您要操作的位置i=  "<<i<<endl;
	cout<<"您要删除的元素是e=  ";
	dellinklist(l,i);
	n--;
	outlinklist(l,n);
	cout<<"您要访问的元素的位置i=  ";
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"您输入的位置错误,请重新输入：i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"您要操作的位置i=  "<<i<<endl;
	getlinklist(l,i);
}
