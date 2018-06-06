#include <iostream.h>
#include <iomanip.h>
//using namespace std;

const int defaultvertices=16;//默认最大顶点数
const int maxweight=-1;

class graphmtx//带权无向图
{
public:
	graphmtx(int sz=defaultvertices);//构造函数
	~graphmtx();//析构函数
	char getvalue(int i);//取顶点i的值
	int getweight(int v1,int v2);//取边(v1，v2)的权值
	int getfirstneighbor(int v);//取顶点v的第一个邻接顶点
	int getnextneighbor(int v,int w);//取v的邻接顶点w的下一邻接顶点
	bool insertvertex(const char & vertex);//插入顶点vertex
	bool insertedge(int v1,int v2,int cost);//插入边v1，v2，权值为cost
	bool removevertex(int v);//删除顶点v及相关联的边
	bool removeedge(int v1,int v2);//在图中删去边(v1,v2);
	friend istream & operator >>(istream & in,graphmtx & g);//输入图的信息
	friend ostream & operator <<(ostream & out,graphmtx & g);//输出图的信息
private:
	int maxvertices;//图中最大顶点数
	int numedges;//当前边数
	int numvertices;//当前顶点数
	char * verticeslist;//顶点表
	int * * edge;//邻接矩阵
	int getvertexpos(char vertex);//给出顶点vertex在图中的位置
};

int main()
{
	graphmtx g;
	cin>>g;
	cout<<g;
	return 0;
}

graphmtx::graphmtx(int sz)//构造函数
{
	maxvertices=sz;numvertices=0;numedges=0;
	int i,j;
	verticeslist=new char[maxvertices];
	edge=new int * [maxvertices];
	for(i=0;i<maxvertices;i++)
		edge[i]=new int [maxvertices];
	for(i=0;i<maxvertices;i++)
		for(j=0;j<maxvertices;j++)
			edge[i][j]=(i==j)?0:maxweight;
	cout<<"无向图构造成功"<<endl;
}

graphmtx::~graphmtx()//析构函数
{
	delete []verticeslist;
	delete []edge;
	cout<<"析构成功"<<endl;
}

int graphmtx::getvertexpos(char v)//给出顶点v在图中的位置
{
	for(int i=0;i<numvertices;i++)
		if(verticeslist[i]==v)
			return i;
	return -1;
}

char graphmtx::getvalue(int i)//取顶点i的值
{
	if(i<0||i>=numvertices)
	{
		cout<<"给出的顶点不存在"<<endl;
		return ' ';
	}
	return verticeslist[i];
}


int graphmtx::getweight(int v1,int v2)//取边(v1，v2)的权值
{
	return edge[v1][v2];
}
	

int graphmtx::getfirstneighbor(int v)//取顶点v的第一个邻接顶点
{
	if(v>=0&&v<numvertices)
	{
		for(int i=0;i<numvertices;i++)
			if(edge[v][i]>0)
				return i;
	}
	return -1;
}
	

int graphmtx::getnextneighbor(int v,int w)//取v的邻接顶点w的下一邻接顶点
{
	if(v>=0&&v<numvertices&&w>=0&&w<numvertices)
		for(int i=w+1;i<numvertices;i++)
			if(edge[v][i]>0)
				return i;
	return -1;
}
	
bool graphmtx::insertvertex(const char & vertex)//插入顶点vertex
{
	if(numvertices<maxvertices)
	{
		verticeslist[numvertices++]=vertex;
		return true;
	}
	return false;
}
	

bool graphmtx::insertedge(int v1,int v2,int cost)//插入边v1，v2，权值为cost
{
	if(v1>=0&&v1<maxvertices&&v2>=0&&v2<maxvertices&&edge[v1][v2]==maxweight)
	{
		edge[v1][v2]=cost;
		edge[v2][v1]=cost;
		numedges++;
		return true;
	}
	return false;
}
	

bool graphmtx::removevertex(int v)//删除顶点v及相关联的边
{
	if(v<0||v>=numvertices)
		return false;
	if(numvertices==1)//只剩一个顶点不删除
		return false;
	int i,j;
	verticeslist[v]=verticeslist[numvertices-1];
	for(i=0;i<numvertices;i++)
		if(edge[v][i]>0)
			numedges--;
	for(i=0;i<numvertices;i++)
		edge[v][i]=edge[numvertices-1][i];
	for(j=0;j<numvertices;j++)
		edge[j][v]=edge[j][numvertices-1];
	numvertices--;
	for(i=0;i<numvertices;i++)
	{
		edge[i][numvertices]=maxweight;
		edge[numvertices][i]=maxweight;
	}
	edge[numvertices][numvertices]=0;
	return true;
}
	

bool graphmtx::removeedge(int v1,int v2)//在图中删去边(v1,v2);
{
	if(v1>=0&&v1<maxvertices&&v2>=0&&v2<maxvertices&&edge[v1][v2]>0)
	{
		edge[v1][v2]=maxweight;
		edge[v2][v1]=maxweight;
		numedges--;
		return true;
	}
	return false;
}


istream & operator >>(istream & in,graphmtx & g)//输入图的信息
{
	int n,m;
	cout<<"请输入顶点的个数：";
	in>>n;
	g.numvertices=n;
	cout<<"请输入每一个顶点的名称：";
	for(int i=0;i<n;i++)
		in>>g.verticeslist[i];
	cout<<"请输入边的条数：";
	in>>m;
	char ta,tb;
	int cost;
	for(i=0;i<m;i++)
	{
		cout<<"请输入每一条边的两个顶点和权值：";
		in>>ta>>tb>>cost;
		int pa=g.getvertexpos(ta);
		int pb=g.getvertexpos(tb);
		g.insertedge(pa,pb,cost);
	}
	return in;
}


ostream & operator << (ostream & out,graphmtx & g)//输出图的信息
{
	out<<setw(4)<<' ';
	for(int k=0;k<g.numvertices;k++)
		out<<setw(4)<<g.verticeslist[k];
	out<<endl;
	for(int i=0;i<g.numvertices;i++)
	{
		out<<setw(4)<<g.verticeslist[i];
		for(int j=0;j<g.numvertices;j++)
			out<<setw(4)<<g.edge[i][j];
		out<<endl;
	}
	return out;
}