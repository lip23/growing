#include <iostream.h>
#include <malloc.h>
typedef struct binode//构造二叉树节点类型
{
	char date;
	struct binode *lchild,*rchild;
}binode,*bitree;



void initbitree(bitree &t)//构造二叉树
{
	t=(bitree)malloc(sizeof(binode));
	if(!t)
		cout<<"二叉树构造失败"<<endl;
	t->lchild=t->rchild=NULL;
	cout<<"二叉树构造成功"<<endl;
}



void creatbitree(bitree &t)//按先序次序输入二叉树中的节点，#表示空树
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


void dlr(bitree t)//先序遍历二叉树
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



void ldr(bitree t)//中续遍历二叉树
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



void lrd(bitree t)//后续遍历二叉树
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
	cout<<"请按先序输入二叉树中的节点,#表示空树"<<endl;
	cout<<"请输入您要创建的二叉树"<<endl;
	creatbitree(t);
	cout<<"二叉树实例化成功"<<endl;
	do
	{
		cout<<"请选择您要遍历的方式 1 先序遍历  2中序遍历  3 后续遍历  4 终止操作"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
			{
				cout<<"先序遍历二叉树的结果是"<<endl;
				dlr(t);
				cout<<endl;
			};break;
		case 2:
			{
				cout<<"中序遍历二叉树的结果是"<<endl;
				ldr(t);
				cout<<endl;
			}break;
		case 3:
			{
				cout<<"后续遍历二叉树的结果是"<<endl;
				lrd(t);
				cout<<endl;
			};break;
		case 4:
			cout<<"操作终止"<<endl;
			break;
		default :
			cout<<"您输入的操作有误，请重新输入"<<endl;
			break;
		}
	}while(a!=4);
}
