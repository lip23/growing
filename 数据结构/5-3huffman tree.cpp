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
	//~huffmantree( ){del(roof);cout<<"�����ɹ�"<<endl;}
	void deltree();//ɾ��������(�ֶ�������������)	
	void settree(char  d,int  q);//����huffmantree�ĳ�ֵ
	void huffman(huffmantree & huf);//�ҳ�huffmantree
	void copyhuf(huffmantree & t);//����huffmantree
	void cld(){del(roof);roof=NULL;}//��huffmantree�ÿ�
	void link(huffmantree & t1,huffmantree & t2);//��������huffmantree
	void display();//��������������ӿ�
	int deep();//�����������ȵĺ����ӿ�
private:
	node * roof;
	void dis(node*,int,int,char s[40][79],int);//���������
	void del(node *);//ɾ�������������нڵ�
	void deep2(int&,node*,int);//������������
	void copytree(node* &,node* &);//���������ƺ���
	void min(huffmantree t[],int & n,huffmantree & temp);//�ҵ�Ȩֵ��С��һ��huffmantree
};

int main()
{
	huffmantree t1;
	t1.huffman(t1);
	t1.display();
	t1.deltree();
	return 0;
}

huffmantree::huffmantree()//���캯��
{
	roof=NULL;
}

void huffmantree::settree(char d,int q)//����ֵ
{
	roof=new node(d,q);
}


void huffmantree::copyhuf(huffmantree & t)//����huffmantree
{
	copytree(t.roof,roof);
}

void huffmantree::copytree(node * & t,node * & n)//���ƶ�����
{
	if(t)
	{
		n=new node(t->date,t->quan);
		copytree(t->lchild,n->lchild);
		copytree(t->rchild,n->rchild);
	}
}

void huffmantree::min(huffmantree t[],int & n,huffmantree & temp)//�ҵ�Ȩֵ��С��һ��huffmantree
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

void huffmantree::huffman(huffmantree & huf)//�ҵ�huffmantree
{
	cout<<"��������Ҫ������huffmantree��Ҷ��������"<<endl;
	int n;
	cin>>n;
	huffmantree * t;
	char  date;
	int  quan;
	t=new huffmantree[n];
	for(int i=0;i<n;i++)
	{
		cout<<"������ڵ����ƺ�Ȩֵ��";
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


void huffmantree::link(huffmantree & t1,huffmantree & t2)//��������huffmantree
{
	roof=new node;
	roof->date=2;
	roof->quan=t1.roof->quan+t2.roof->quan;
	roof->lchild=t1.roof;
	roof->rchild=t2.roof;
}

void huffmantree::del(node *p)//ɾ�������������нڵ�
{
	if(p)
	{
		del(p->lchild);
		del(p->rchild);
		delete p;
	}
}


void huffmantree::display()//��������������Ľӿ�
{
	char s[40][79];
	for(int i=0;i<40;i++)
		for(int k=0;k<79;k++)
			s[i][k]=' ';
	int d=deep();
	if(d==0)
		cout<<"�ö�����Ϊ����"<<endl;
	else if(d==1)
		cout<<"�ö�����ֻ��һ�����ڵ㣺"<<roof->date<<endl;
	else if(d>6)
		cout<<"�ö�����̫���޷���ʾ"<<endl;
	else
	{
		int temp=1;
		for(int i=0;i<d-2;i++)
			temp*=2;
		dis(roof,0,39,s,temp);
		cout<<"�ö�����Ϊ��"<<endl;
		for(int i=0;i<temp*2;i++)
		{
			for(int k=0;k<79;k++)
				cout<<s[i][k];
			cout<<endl;
		}
	}
}

void huffmantree::dis(node * t,int tx,int ty,char s[40][79],int temp)//���������
{
	if(t)
	{
		s[tx][ty]=t->date;
	    dis(t->lchild,tx+temp,ty-temp,s,temp/2);
	    dis(t->rchild,tx+temp,ty+temp,s,temp/2);
	}
}

void huffmantree::deltree()//ɾ��������
{
	del(roof);
	//cout<<"�����ɹ�"<<endl;
	//cout<<"������ɾ���ɹ�"<<endl;
}


int huffmantree::deep()//���������Ⱥ����ӿ�
{
    int d=0;
	int tj=0;
	deep2(d,roof,tj);
	return d;
}

void huffmantree::deep2(int& d,node* t,int tj)//����������
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
