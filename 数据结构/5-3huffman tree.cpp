#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	char date;
	int quan;
	node * lchild;
	node * rchild;
	node()
	{
		lchild=NULL;
		rchild=NULL;
	}
	node(char m):date(m)
	{
		lchild=NULL;
		rchild=NULL;
	}
	node (char d,int q):date(d),quan(q)
	{
		lchild=NULL;
		rchild=NULL;
	}
};

class huffmantree
{
public:
	huffmantree();
	//~huffmantree( ){del(roof);cout<<"析构成功"<<endl;}
	void deltree();//删除二叉树(手动调用析构函数)	
	void settree(char  d,int  q);//设置huffmantree的初值
	void huffman(huffmantree & huf);//找出huffmantree
	void copyhuf(huffmantree & t);//复制huffmantree
	void cld(){del(roof);roof=NULL;}//将huffmantree置空
	void link(huffmantree & t1,huffmantree & t2);//链接两棵huffmantree
	void display();//输出二叉树函数接口
	int deep();//求二叉树的深度的函数接口
private:
	node * roof;
	void dis(node*,int,int,char s[40][79],int);//输出二叉树
	void del(node *);//删除二叉树的所有节点
	void deep2(int&,node*,int);//求二叉树的深度
	void copytree(node* &,node* &);//二叉树复制函数
	void min(huffmantree t[],int & n,huffmantree & temp);//找到权值最小的一颗huffmantree
};

int main()
{
	huffmantree t1;
	t1.huffman(t1);
	t1.display();
	t1.deltree();
	return 0;
}

huffmantree::huffmantree()//构造函数
{
	roof=NULL;
}

void huffmantree::settree(char d,int q)//赋初值
{
	roof=new node(d,q);
}


void huffmantree::copyhuf(huffmantree & t)//复制huffmantree
{
	copytree(t.roof,roof);
}

void huffmantree::copytree(node * & t,node * & n)//复制二叉树
{
	if(t)
	{
		n=new node(t->date,t->quan);
		copytree(t->lchild,n->lchild);
		copytree(t->rchild,n->rchild);
	}
}

void huffmantree::min(huffmantree t[],int & n,huffmantree & temp)//找到权值最小的一颗huffmantree
{
	int m=0;
	for(int i=0;i<n;i++)
		if(t[i].roof->quan<t[m].roof->quan)
			m=i;
	temp.copyhuf(t[m]);
	t[m].cld();
	if(m!=n-1)
	{
		t[m].copyhuf(t[n-1]);
		t[n-1].cld();
	}
	n--;
}

void huffmantree::huffman(huffmantree & huf)//找到huffmantree
{
	cout<<"请输入您要创建的huffmantree的叶结点个数："<<endl;
	int n;
	cin>>n;
	huffmantree * t;
	char  date;
	int  quan;
	t=new huffmantree[n];
	for(int i=0;i<n;i++)
	{
		cout<<"请输入节点名称和权值：";
		cin>>date>>quan;
		t[i].settree(date,quan);
	}
	while(n>=2)
	{
		if(n>2)
		{
			huffmantree min1,min2,min3;
			min(t,n,min1);
			min(t,n,min2);
			min3.link(min1,min2);
			t[n].copyhuf(min3);
			min3.deltree();
			n++;
		}
		else if(n==2)
		{
			huf.link(t[0],t[1]);
			break;
		}
	}
}


void huffmantree::link(huffmantree & t1,huffmantree & t2)//链接两棵huffmantree
{
	roof=new node;
	roof->date=2;
	roof->quan=t1.roof->quan+t2.roof->quan;
	roof->lchild=t1.roof;
	roof->rchild=t2.roof;
}

void huffmantree::del(node *p)//删除二叉树的所有节点
{
	if(p)
	{
		del(p->lchild);
		del(p->rchild);
		delete p;
	}
}


void huffmantree::display()//二叉树输出函数的接口
{
	char s[40][79];
	for(int i=0;i<40;i++)
		for(int k=0;k<79;k++)
			s[i][k]=' ';
	int d=deep();
	if(d==0)
		cout<<"该二叉树为空树"<<endl;
	else if(d==1)
		cout<<"该二叉树只有一个根节点："<<roof->date<<endl;
	else if(d>6)
		cout<<"该二叉树太大无法显示"<<endl;
	else
	{
		int temp=1;
		for(int i=0;i<d-2;i++)
			temp*=2;
		dis(roof,0,39,s,temp);
		cout<<"该二叉树为："<<endl;
		for(int i=0;i<temp*2;i++)
		{
			for(int k=0;k<79;k++)
				cout<<s[i][k];
			cout<<endl;
		}
	}
}

void huffmantree::dis(node * t,int tx,int ty,char s[40][79],int temp)//二叉树输出
{
	if(t)
	{
		s[tx][ty]=t->date;
	    dis(t->lchild,tx+temp,ty-temp,s,temp/2);
	    dis(t->rchild,tx+temp,ty+temp,s,temp/2);
	}
}

void huffmantree::deltree()//删除二叉树
{
	del(roof);
	//cout<<"析构成功"<<endl;
	//cout<<"二叉树删除成功"<<endl;
}


int huffmantree::deep()//求二叉树深度函数接口
{
    int d=0;
	int tj=0;
	deep2(d,roof,tj);
	return d;
}

void huffmantree::deep2(int& d,node* t,int tj)//求二叉树深度
{
	if(t)
	{
		int temp=tj+1;
		if(temp>d)
			d=temp;
		deep2(d,t->lchild,temp);
		deep2(d,t->rchild,temp);
	}
}
