#include <iostream>
using namespace std;

const int defaultver=16;//默认最大顶点数
const int maxweight=-1;

struct edge//边节点的定义
{
	int dest;//边的另一顶点位置
	int cost;//边的权值
	edge * link;//下一条边链指针
};


struct vertex//顶点的定义
{
	char date;//顶点名称
	edge * adj;//边链表的头指针
};


class graphlnk//带权无向图
{
public:
	graphlnk(int sz=defaultver);//构造函数
	~graphlnk();//析构函数
	char getvalue(int i);//取顶点i的值
	int getweight(int v1,int v2);//取边(v1，v2)的权值
	int getfirstneighbor(int v);//取顶点v的第一个邻接顶点
	int getnextneighbor(int v,int w);//取v的邻接顶点w的下一邻接顶点
	bool insertvertex(const char & vertex);//插入顶点vertex
	bool insertedge(int v1,int v2,int cost);//插入边v1，v2，权值为cost
	bool removevertex(int v);//删除顶点v及相关联的边
	bool removeedge(int v1,int v2);//在图中删去边(v1,v2);
	//friend istream & operator >>(istream & in,graphmtx & g);//输入图的信息
	//friend ostream & operator <<(ostream & out,graphmtx & g);//输出图的信息
private:
	int numver;//当前顶点数
	int numed;//当前边数
	int maxver;//当前最大顶点数
	vertex * nodetable;//顶点表
	int getvertexpos(const char vertex);//给出顶点vertex在图中的位置
};

int main()
{
	graphlnk g;
	return 0;
}


graphlnk::graphlnk(int sz)//构造函数
{
	maxver=sz;numver=0;numed=0;
	nodetable=new vertex[sz];
	if(!nodetable)
	{
		cerr<<"内存分配失败"<<endl;
		exit(1);
	}
	for(int i=0;i<maxver;i++)
		nodetable[i].adj=NULL;
	cout<<"无向图构造成功"<<endl;
}


graphlnk::~graphlnk()//析构函数
{
	for(int i=0;i<numver;i++)
	{
		edge * temp=nodetable[i].adj;//删除各边链表的节点
		while(temp)
		{
			edge * del=temp;
			temp=temp->link;
			delete del;
		}
	}
	delete [] nodetable;//删除顶点表数组
	cout<<"析构成功"<<endl;
}


int graphlnk::getvertexpos(const char v)//给出顶点vertex在图中的位置
{
	for(int i=0;i<numver;i++)
		if(nodetable[i].date==v)
			return i;
	return -1;
}


char graphlnk::getvalue(int i)//取顶点i的值
{
	if(i<0||i>=numver)
	{
		cout<<"输入的位置错误"<<endl;
		return ' ';
	}
	return nodetable[i].date;
}

	
int graphlnk::getweight(int v1,int v2)//取边(v1，v2)的权值
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"输入的位置错误"<<endl;
		return -1;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(!temp)
		return -1;
	return temp->cost;
}

	
int graphlnk::getfirstneighbor(int v)//取顶点v的第一个邻接顶点
{
	if(v<0||v>=numver)
	{
		cout<<"输入的位置错误"<<endl;
		return -1;
	}
	return nodetable[v].adj==NULL?-1:nodetable[v].adj->dest;
}

	
int graphlnk::getnextneighbor(int v,int w)//取v的邻接顶点w的下一邻接顶点
{
	if(v<0||v>=numver||w<0||w>numver)
	{
		cout<<"输入的位置错误"<<endl;
		return -1;
	}
	edge * temp=nodetable[v].adj;
	while(temp&&temp->dest!=w)
		temp=temp->link;
	if(!temp||!temp->link)
		return -1;
	return temp->link->dest;
}


bool graphlnk::insertvertex(const char & vertex)//插入顶点vertex
{
	if(numver==maxver)
		return false;
	nodetable[numver].date=vertex;
	nodetable[numver].adj=NULL;
	numver++;
	return true;
}

	
bool graphlnk::insertedge(int v1,int v2,int c)//插入边v1，v2，权值为cost
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"输入的位置错误"<<endl;
		return false;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(temp)
	{
		cout<<"要插入的边已经存在"<<endl;
		return false;
	}
	edge * newed=new edge;//链入v1边链表
	newed->cost=c;
	newed->dest=v2;
	newed->link=nodetable[v1].adj;
	nodetable[v1].adj=newed;
	edge * newed2=new edge;//链入v2边链表
	newed2->cost=c;
	newed2->dest=v1;
	newed2->link=nodetable[v2].adj;
	nodetable[v2].adj=newed2;
	numed++;
	return true;
}
	

bool graphlnk::removevertex(int v)//删除顶点v及相关联的边
{
	if(v<0||v>=numver)
	{
		cout<<"输入的位置错误"<<endl;
		return true;
	}
	if(numver==1)
	{
		cout<<"只有一个结点，删除失败"<<endl;
		return false;
	}
	edge * del=nodetable[v].adj;//删除头结点为v1的边链表
	while(del)
	{
		edge * d=del;
		del=del->link;
		delete d;
		numed--;
	}
	nodetable[v].adj=NULL;
	for(int i=0;i<numver;i++)//删除其它头结点中包含v的边
	{
		edge * p=nodetable[i].adj;
		edge * q;
		edge * s=p;
		while(p&&p->dest!=v)
		{
			q=p;
			p=p->link;
		}
		if(p)//该边链表中含有v的边
		{
			if(p==s){nodetable[i].adj=NULL;delete p;}//该边链表中只有一个边
			else{q->link=p->link;delete p;}
		}
	}
	if(v!=numver-1)//填补
	{
		nodetable[v].date=nodetable[numver-1].date;
		nodetable[v].adj=nodetable[numver-1].adj;
		edge * p=nodetable[v].adj;
		while(p)
		{
			int s=p->dest;
			edge * q=nodetable[s].adj;
			while(q->dest!=numver-1)
				q=q->link;
			q->dest=v;
			p=p->link;
		}
	}
    nodetable[numver-1].adj=NULL;
	numver--;
	return true;
}
	

bool graphlnk::removeedge(int v1,int v2)//在图中删去边(v1,v2);
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"输入的位置错误"<<endl;
		return false;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(!temp)
	{
		cout<<"要删除的边不存在"<<endl;
		return false;
	}
	if(nodetable[v1].adj->dest==v2)//删除边<v1,v2>
	{
		edge * del=nodetable[v1].adj;
		nodetable[v1].adj=del->link;
		delete del;
	}
	else
	{
		edge * del=nodetable[v1].adj;
		while(del->link->dest!=v2)
			del=del->link;
		edge * d=del->link;
		del->link=d->link;
		delete d;
	}
	if(nodetable[v2].adj->dest==v1)//删除边<v2,v1>
	{
		edge * del=nodetable[v2].adj;
		nodetable[v2].adj=del->link;
		delete del;
	}
	else
	{
		edge * del=nodetable[v2].adj;
		while(del->link->dest!=v1)
			del=del->link;
		edge * d=del->link;
		del->link=d->link;
		delete d;
	}
	numed--;
	return true;
}

