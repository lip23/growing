#include <iostream.h>
#include <malloc.h>
typedef struct lnode//����ڵ����ͣ�Ԫ��+ָ��=�ڵ�
{
	int date;//Ԫ������
	struct lnode *next;//����ָ������Ϊlnode��ָ��
}lnode,*linklist;//�����ṹ��������һ������ṹ�����ڶ�������ṹ��ָ����



void creatlinklist(linklist &l,int n)//����n���ڵ������
{
	linklist p;
	l=(linklist)malloc(sizeof(lnode));//malloc��������һ��Ԫ������Ϊlnode��linklist��lnode*��ָ��
	l->next=NULL;
	cout<<"���������������Ԫ��"<<endl;
	for(n;n>0;n--)
	{
		p=(linklist)malloc(sizeof(lnode));
		cin>>(p->date);
		p->next=l->next;
		l->next=p;
	}
}



void outlinklist(linklist l,int n)//�������
{
	linklist q;
	linklist p;
	p=l->next;
	cout<<"�����˳���ǣ�"<<endl;
	for(int i=n;i>0;i--)
	{
		cout<<p->date<<"  ";
		q=p;
		p=q->next;
	}
	cout<<endl;
}


void pushlinklist(linklist &l,int e,int i,int n)//������l�ĵ�iλ�ò���e��
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



void dellinklist(linklist &l,int i)//ɾ����i��Ԫ��
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
	int n;//������
	int e;
	int i;
	linklist l;
	cout<<"��������Ҫ����������Ĵ�С"<<endl;
	cin>>n;
	creatlinklist(l,n);
	outlinklist(l,n);
	cout<<"��������Ҫ�����Ԫ��e=  ";
	cin>>e;
	cout<<endl;
	cout<<"��������Ҫ�����Ԫ��λ��i=  ";
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"�������λ�ô���,���������룺i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"��Ҫ������λ��i=  "<<i<<endl;
	pushlinklist(l,e,i,n);
	n++;
	outlinklist(l,n);
	cout<<"��������Ҫɾ��Ԫ�ص�λ��i=  "<<endl;
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"�������λ�ô���,���������룺i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"��Ҫ������λ��i=  "<<i<<endl;
	cout<<"��Ҫɾ����Ԫ����e=  ";
	dellinklist(l,i);
	n--;
	outlinklist(l,n);
	cout<<"��Ҫ���ʵ�Ԫ�ص�λ��i=  ";
	cin>>i;
	cout<<endl;
	while(i<0||i>n)
	{
		cout<<"�������λ�ô���,���������룺i=  ";
		cin>>i;
		cout<<endl;
	}
	cout<<"��Ҫ������λ��i=  "<<i<<endl;
	getlinklist(l,i);
}
