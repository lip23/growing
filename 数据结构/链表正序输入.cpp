#include <iostream.h>
#include <malloc.h>
typedef struct lnode 
{
	int date;
	struct lnode *next;
}londe,*linklist;


void main()
{
	linklist l;
	int n;
	l=(linklist)malloc(sizeof(lnode));
	l->next=NULL;
	linklist p;
	linklist c;
	c=l;
	cout<<"请输入您要创建的链表的大小n=  "<<endl;
	cin>>n;
	cout<<endl;
	cout<<"请输入链表中的元素"<<endl;
	for(int i=1;i<=n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		c->next=p;
		c=p;
		cin>>c->date;
	}
	cout<<"您创建的链表是"<<endl;
	linklist q;
	q=l;
	for(int m=1;m<=n;m++)
	{
		q=q->next;
		cout<<q->date<<endl;
	}
}

		
	

	