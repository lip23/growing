#include <iostream.h>
#include <malloc.h>
typedef struct qnode//������нڵ�Ľṹ������
{
	int date;
	struct qnode *next;
}qnode,*linkqnode;


typedef struct     //������еĽṹ������
{
	linkqnode front;
	linkqnode rear;
	int size;
}linkqueue;


void initqueue(linkqueue &l)//����һ���ն���
{
	l.front=l.rear=(linkqnode)malloc(sizeof(qnode));
	if(!l.front)
		cout<<"���г�ʼ��ʧ��"<<endl;
	l.front->next=NULL;
	l.size=0;
	cout<<"���г�ʼ���ɹ�"<<endl;
}


void enqueue(linkqueue &l,int e)//����Ԫ��eΪl���µĶ�βԪ��
{
	linkqnode p;
	p=(linkqnode)malloc(sizeof(qnode));
	if(!p)
		cout<<"�洢����ʧ��"<<endl;
	p->date=e;
	p->next=NULL;
	l.rear->next=p;
	l.rear=p;
	l.size++;
	cout<<"����ɹ�"<<endl;
}


void dequeue(linkqueue &l,int &e)//�����в��գ���ɾ��l�Ķ�ͷԪ�أ���e������ֵ��
{
	linkqnode p;
	if(l.front==l.rear)
		cout<<"����Ϊ�գ���ֹ����"<<endl;
	p=l.front->next;
	e=p->date;
	l.front->next=p->next;
	if(l.rear==p)
		l.rear=l.front;
	free(p);
	cout<<"��ͷԪ��ɾ���ɹ�"<<endl;
	l.size--;
}


void destroyqueue(linkqueue &l)//���ٶ���
{
	while(l.front)
	{
		l.rear=l.front->next;
		free(l.front);
		l.front=l.rear;
	}
	cout<<"�����ѳɹ�����"<<endl;
}


void putout(linkqueue l)//�����ǰ�����е�Ԫ��
{
	linkqnode p;
	p=(linkqnode)malloc(sizeof(qnode));
	p=l.front->next;
	cout<<"��ǰ�����е�Ԫ����"<<endl;
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
		cout<<endl<<"��ѡ����Ҫִ�еĲ�����a Ԫ�ؽ��ӣ�b Ԫ�س��ӣ�c ���ٶ���"<<endl;
		cin>>m;
		cout<<endl;
		if(m=='a')
		{
			int e;
			cout<<"��������Ҫ��ӵ�Ԫ��e=  ";
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
			cout<<"������Ĳ�����������������"<<endl;
			cin>>m;
		}
	}while(m!='c');	
}