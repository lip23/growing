#include <iostream.h>
#include <malloc.h>
typedef struct stack
{
	int date;
	struct stack *next;
}stack,*linkstack;


void creatlinkstack(linkstack &top,int n)//����һ����СΪn��ջ
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


void pushlinkstack(linkstack top,int n)//���ջ��Ԫ��
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


void putlinkstack(linkstack &top)//�ڲ���Ԫ��e
{
	linkstack p;
	int e;
	p=(linkstack)malloc(sizeof(stack));
	cout<<"��������Ҫ�����Ԫ��e=  ";
	cin>>e;
	cout<<endl;
	p->date=e;
	p->next=top->next;
	top->next=p;
}



void dellinkstack(linkstack &top)//ɾ��ջ��Ԫ�ز���e����
{
	int e;
	e=top->next->date;
	cout<<"��Ҫɾ����ջ��Ԫ����  "<<e<<endl;
	top->next=top->next->next;
}



void toplinkstack(linkstack top)//����ջ��Ԫ��
{
	int e;
	e=top->next->date;
	cout<<"��ջ��ջ��Ԫ��e=  "<<e<<endl;
}


/*int caozuo( )//ѡ����Ҫִ�еĲ���
{
	int m;
	cout<<"��ѡ����Ҫִ�еĲ��� 1 ����ջ��Ԫ�� 2 ɾ��ջ��Ԫ�� 3����ջ��Ԫ�� 4��ֹ����"<<endl;
	cin>>m;
	return m;
}*/







void main()
{
	int n;//ջ�Ĵ�С
	int m;//ִ�еĲ���
	linkstack top;
	cout<<"��������Ҫ������ջ�Ĵ�Сn=  ";
	cin>>n;
	cout<<endl;
	cout<<"��������ջ�е�Ԫ��"<<endl;
	creatlinkstack(top,n);
	cout<<"��������ջ��������"<<endl;
	pushlinkstack(top,n);
	cout<<"��ѡ����Ҫִ�еĲ��� 1 ����ջ��Ԫ�� 2 ɾ��ջ��Ԫ�� 3����ջ��Ԫ�� 4��ֹ����"<<endl;
	cin>>m;
	while(m<1||m>4)
	{
		cout<<"����Ĳ�����������������m=  ";
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
		cout<<"��ѡ����Ҫִ�еĲ��� 1 ����ջ��Ԫ�� 2 ɾ��ջ��Ԫ�� 3����ջ��Ԫ�� 4��ֹ����"<<endl;
		cin>>m;
	}
}











