#include <iostream.h>
#include <malloc.h>
typedef struct //�������е����Դ洢�ṹ
{
	int* elem;
	int size;
}sqqueue;


void initsqqueue(sqqueue &q,int n)//��ʼ����СΪn�Ķ���
{
	
	q.elem=(int*)malloc((n+10)*(sizeof(int)));
	if(!q.elem)
		cout<<"���г�ʼ��ʧ��"<<endl;
	q.size=n;
	cout<<"�������ʼ�������е�Ԫ��"<<endl;
	for(int i=1;i<=n;i++)
		cin>>q.elem[i];
	cout<<"���г�ʼ���ɹ�"<<endl;
}


void putout(sqqueue q)
{
	cout<<"��ǰ�����е�Ԫ����"<<endl;
		for(int i=1;i<=q.size;i++)
			cout<<q.elem[i]<<"  ";
}


void enqueue(sqqueue &q)//����Ԫ��eΪq���¶�βԪ��
{
	int e;
	cout<<endl<<"��������Ҫ��ӵ�Ԫ��e=  ";
	cin>>e;
	cout<<endl;
	q.size++;
	q.elem[q.size]=e;
}


void dequeue(sqqueue &q)//�����в��գ���ɾ��q�Ķ�ͷԪ�أ���e������ֵ
{
	int e;
	if(q.size==0)
	{
		cout<<"����Ϊ��"<<endl;
	}
	else
	{
		e=q.elem[1];
		q.size--;
		cout<<"���ӵ�Ԫ��e=  "<<e<<endl;
		for(int i=1;i<=q.size;i++)
			q.elem [i]=q.elem[i+1];
	}
}





void main()
{
	int n;
	char m;
	sqqueue q;
	cout<<"��������Ҫ�����Ķ��еĴ�Сn=  ";
	cin>>n;
	initsqqueue(q,n);
	putout(q);
	do
	{
		cout<<endl<<"��������Ҫִ�еĲ��� aԪ�����  bԪ�س���  c��ֹ����"<<endl;
		cin>>m;
		if(m=='a')
		{
			enqueue(q);
			putout(q);
		}
		else if(m=='b')
		{
			dequeue(q);
			if(q.size==0)
			{
				cout<<"��ǰ�����ѿ�,������ֹ"<<endl;
				m='c';
			}
			else
			{
				putout(q);
			}
		}
		else
			cout<<"�������������������������"<<endl;
	}while(m!='c');
}
	
