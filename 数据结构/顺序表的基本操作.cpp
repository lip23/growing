#include <iostream.h>
#include <malloc.h>
#define LIST_INIT_SIZE 5 
#define LISTINCREMENT 5
 

typedef struct Sqlist
{
 int *elem;
 int length;
 int listsize;
}list;//建立list数据类型
 

int Initlist(list &l)
{
 l.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
 if(!l.elem) 
  return 0;
 l.length=0;
 l.listsize=LIST_INIT_SIZE;
 return 1;
}//初始化线性表
 

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
}//实例化线性表
 

int listlength(list l)
{
 return l.length;
}//获取线性表长度
 

void getelem(list l,int i)
{
	if(i<0||i>l.length)
	 {
		 cout<<"您输入的数有误"<<endl;
	     //return 0;
	 }
	 else
		 cout<<l.elem[i-1]<<endl;
}//查找第i个元素
 

void delelem(list &l,int i)
{
	if(i<0||i>l.length)
	{
		cout<<"您输入的数有误"<<endl;
	}
	else
	{
	 cout<<l.elem[i-1]<<endl;
	 cout<<"线性表的新组合是： "<<endl;
	 for((i-1);i<=(l.length-1);i++)
		 l.elem[i-1]=l.elem[i];
	 for(i=0;i<=(l.length-2);i++)
		 cout<<l.elem[i]<<"  ";
	 cout<<endl;
	 cout<<"线性表的长度是：  "<<--l.length;
	};
}//删除第i个元素
 

void listinsert(list &l,int i,int a)
{
	int m;
	for(m=LIST_INIT_SIZE;m>=i;m--)
		l.elem[m]=l.elem[m-1];
	l.elem[i-1]=a;
	for(m=0;m<LIST_INIT_SIZE;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
 }//在线性表中第i个位置插入a
 

void main()
{
 list l;//初始化元素类型为list的元素l
 int e;//对地e个元素进行操作
 int m;
 int jude;//定义一个整型变量，判断线性表是否初始化成功
 jude=Initlist(l);
 if(jude)
  cout<<"线性表初始化成功!"<<endl;
 else
  cout<<"failed"<<endl;
 cout<<"********************************************"<<endl;
 cout<<"请输入线性表的元素"<<endl;
 creatlist(l,LIST_INIT_SIZE);
 cout<<endl;
 cout<<"********************************************"<<endl;
 cout<<"线性表的长度是 "<<listlength(l)<<endl;
 cout<<"********************************************"<<endl;
 cout<<"请输入您要查找的元素序号,e=   ";
 cin>>e;
 getelem(l,e);
 cout<<"********************************************"<<endl;
 cout<<"请输入您要删除的元素序号,m=   ";
 cin>>m;
 delelem(l,m);
 cout<<endl;
 cout<<"********************************************"<<endl;
 cout<<"请输入你要插入的元素的位置，e=   ";
 cin>>e;
 cout<<endl<<"请输入你要插入的元素，m=   ";
 cin>>m;
 cout<<endl<<"新线性表的元素为：";
 listinsert(l,e,m);
}