#include <iostream.h>
#include <malloc.h>
typedef struct binode//����������ڵ�����
{
	char date;
	struct binode *lchild,*rchild;
}binode,*bitree;



void initbitree(bitree &t)//���������
{
	t=(bitree)malloc(sizeof(binode));
	if(!t)
		cout<<"����������ʧ��"<<endl;
	t->lchild=t->rchild=NULL;
	cout<<"����������ɹ�"<<endl;
}



void creatbitree(bitree &t)//�������������������еĽڵ㣬#��ʾ����
{
	char m;
	cin>>m;
	if(m=='#')
		t=NULL;
	else
	{
		t=(bitree)malloc(sizeof(binode));
		t->date=m;
		creatbitree(t->lchild);
		creatbitree(t->rchild);
	}
}


void dlr(bitree t)//�������������
{
	if(t)
	{
		cout<<t->date;
		dlr(t->lchild);
		dlr(t->rchild);
	}
	else
		cout<<"#";
}



void ldr(bitree t)//��������������
{
	if(t)
	{
		ldr(t->lchild);
		cout<<t->date;
		ldr(t->rchild);
	}
	else
		cout<<"#";
}



void lrd(bitree t)//��������������
{
	if(t)
	{
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->date;
	}
	else 
		cout<<"#";
}





void main()
{
	bitree t;
	int a;
	initbitree(t);
	cout<<"�밴��������������еĽڵ�,#��ʾ����"<<endl;
	cout<<"��������Ҫ�����Ķ�����"<<endl;
	creatbitree(t);
	cout<<"������ʵ�����ɹ�"<<endl;
	do
	{
		cout<<"��ѡ����Ҫ�����ķ�ʽ 1 �������  2�������  3 ��������  4 ��ֹ����"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"��������������Ľ����"<<endl;
				dlr(t);
				cout<<endl;
			};break;
		case 2:
			{
				cout<<"��������������Ľ����"<<endl;
				ldr(t);
				cout<<endl;
			}break;
		case 3:
			{
				cout<<"���������������Ľ����"<<endl;
				lrd(t);
				cout<<endl;
			};break;
		case 4:
			cout<<"������ֹ"<<endl;
			break;
		default :
			cout<<"������Ĳ�����������������"<<endl;
			break;
		}
	}while(a!=4);
}
