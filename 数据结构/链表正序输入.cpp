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
	cout<<"��������Ҫ����������Ĵ�Сn=  "<<endl;
	cin>>n;
	cout<<endl;
	cout<<"�����������е�Ԫ��"<<endl;
	for(int i=1;i<=n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		c->next=p;
		c=p;
		cin>>c->date;
	}
	cout<<"��������������"<<endl;
	linklist q;
	q=l;
	for(int m=1;m<=n;m++)
	{
		q=q->next;
		cout<<q->date<<endl;
	}
}

		
	

	