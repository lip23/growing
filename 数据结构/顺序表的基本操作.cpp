#include <iostream.h>
#include <malloc.h>
#define LIST_INIT_SIZE 5 
#define LISTINCREMENT 5
 

typedef struct Sqlist
{
 int *elem;
 int length;
 int listsize;
}list;//����list��������
 

int Initlist(list &l)
{
 l.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
 if(!l.elem) 
  return 0;
 l.length=0;
 l.listsize=LIST_INIT_SIZE;
 return 1;
}//��ʼ�����Ա�
 

void creatlist(list &l,int y)
{
 int a=y;
 for(int i=0;i<a;i++)
 {
  cin>>l.elem[i];
  l.length++;
 }
 cout<<"*****************************************"<<endl;
 for(int j=0;j<a;j++)
  cout<<l.elem[j]<<"   ";
}//ʵ�������Ա�
 

int listlength(list l)
{
 return l.length;
}//��ȡ���Ա���
 

void getelem(list l,int i)
{
	if(i<0||i>l.length)
	 {
		 cout<<"�������������"<<endl;
	     //return 0;
	 }
	 else
		 cout<<l.elem[i-1]<<endl;
}//���ҵ�i��Ԫ��
 

void delelem(list &l,int i)
{
	if(i<0||i>l.length)
	{
		cout<<"�������������"<<endl;
	}
	else
	{
	 cout<<l.elem[i-1]<<endl;
	 cout<<"���Ա��������ǣ� "<<endl;
	 for((i-1);i<=(l.length-1);i++)
		 l.elem[i-1]=l.elem[i];
	 for(i=0;i<=(l.length-2);i++)
		 cout<<l.elem[i]<<"  ";
	 cout<<endl;
	 cout<<"���Ա�ĳ����ǣ�  "<<--l.length;
	};
}//ɾ����i��Ԫ��
 

void listinsert(list &l,int i,int a)
{
	int m;
	for(m=LIST_INIT_SIZE;m>=i;m--)
		l.elem[m]=l.elem[m-1];
	l.elem[i-1]=a;
	for(m=0;m<LIST_INIT_SIZE;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
 }//�����Ա��е�i��λ�ò���a
 

void main()
{
 list l;//��ʼ��Ԫ������Ϊlist��Ԫ��l
 int e;//�Ե�e��Ԫ�ؽ��в���
 int m;
 int jude;//����һ�����ͱ������ж����Ա��Ƿ��ʼ���ɹ�
 jude=Initlist(l);
 if(jude)
  cout<<"���Ա��ʼ���ɹ�!"<<endl;
 else
  cout<<"failed"<<endl;
 cout<<"********************************************"<<endl;
 cout<<"���������Ա��Ԫ��"<<endl;
 creatlist(l,LIST_INIT_SIZE);
 cout<<endl;
 cout<<"********************************************"<<endl;
 cout<<"���Ա�ĳ����� "<<listlength(l)<<endl;
 cout<<"********************************************"<<endl;
 cout<<"��������Ҫ���ҵ�Ԫ�����,e=   ";
 cin>>e;
 getelem(l,e);
 cout<<"********************************************"<<endl;
 cout<<"��������Ҫɾ����Ԫ�����,m=   ";
 cin>>m;
 delelem(l,m);
 cout<<endl;
 cout<<"********************************************"<<endl;
 cout<<"��������Ҫ�����Ԫ�ص�λ�ã�e=   ";
 cin>>e;
 cout<<endl<<"��������Ҫ�����Ԫ�أ�m=   ";
 cin>>m;
 cout<<endl<<"�����Ա��Ԫ��Ϊ��";
 listinsert(l,e,m);
}