#include <iostream.h>
#include <iomanip.h>
//using namespace std;

const int defaultvertices=16;//Ĭ����󶥵���
const int maxweight=-1;

class graphmtx//��Ȩ����ͼ
{
public:
	graphmtx(int sz=defaultvertices);//���캯��
	~graphmtx();//��������
	char getvalue(int i);//ȡ����i��ֵ
	int getweight(int v1,int v2);//ȡ��(v1��v2)��Ȩֵ
	int getfirstneighbor(int v);//ȡ����v�ĵ�һ���ڽӶ���
	int getnextneighbor(int v,int w);//ȡv���ڽӶ���w����һ�ڽӶ���
	bool insertvertex(const char & vertex);//���붥��vertex
	bool insertedge(int v1,int v2,int cost);//�����v1��v2��ȨֵΪcost
	bool removevertex(int v);//ɾ������v��������ı�
	bool removeedge(int v1,int v2);//��ͼ��ɾȥ��(v1,v2);
	friend istream & operator >>(istream & in,graphmtx & g);//����ͼ����Ϣ
	friend ostream & operator <<(ostream & out,graphmtx & g);//���ͼ����Ϣ
private:
	int maxvertices;//ͼ����󶥵���
	int numedges;//��ǰ����
	int numvertices;//��ǰ������
	char * verticeslist;//�����
	int * * edge;//�ڽӾ���
	int getvertexpos(char vertex);//��������vertex��ͼ�е�λ��
};

int main()
{
	graphmtx g;
	cin>>g;
	cout<<g;
	return 0;
}

graphmtx::graphmtx(int sz)//���캯��
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
	cout<<"����ͼ����ɹ�"<<endl;
}

graphmtx::~graphmtx()//��������
{
	delete []verticeslist;
	delete []edge;
	cout<<"�����ɹ�"<<endl;
}

int graphmtx::getvertexpos(char v)//��������v��ͼ�е�λ��
{
	for(int i=0;i<numvertices;i++)
		if(verticeslist[i]==v)
			return i;
	return -1;
}

char graphmtx::getvalue(int i)//ȡ����i��ֵ
{
	if(i<0||i>=numvertices)
	{
		cout<<"�����Ķ��㲻����"<<endl;
		return ' ';
	}
	return verticeslist[i];
}


int graphmtx::getweight(int v1,int v2)//ȡ��(v1��v2)��Ȩֵ
{
	return edge[v1][v2];
}
	

int graphmtx::getfirstneighbor(int v)//ȡ����v�ĵ�һ���ڽӶ���
{
	if(v>=0&&v<numvertices)
	{
		for(int i=0;i<numvertices;i++)
			if(edge[v][i]>0)
				return i;
	}
	return -1;
}
	

int graphmtx::getnextneighbor(int v,int w)//ȡv���ڽӶ���w����һ�ڽӶ���
{
	if(v>=0&&v<numvertices&&w>=0&&w<numvertices)
		for(int i=w+1;i<numvertices;i++)
			if(edge[v][i]>0)
				return i;
	return -1;
}
	
bool graphmtx::insertvertex(const char & vertex)//���붥��vertex
{
	if(numvertices<maxvertices)
	{
		verticeslist[numvertices++]=vertex;
		return true;
	}
	return false;
}
	

bool graphmtx::insertedge(int v1,int v2,int cost)//�����v1��v2��ȨֵΪcost
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
	

bool graphmtx::removevertex(int v)//ɾ������v��������ı�
{
	if(v<0||v>=numvertices)
		return false;
	if(numvertices==1)//ֻʣһ�����㲻ɾ��
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
	

bool graphmtx::removeedge(int v1,int v2)//��ͼ��ɾȥ��(v1,v2);
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


istream & operator >>(istream & in,graphmtx & g)//����ͼ����Ϣ
{
	int n,m;
	cout<<"�����붥��ĸ�����";
	in>>n;
	g.numvertices=n;
	cout<<"������ÿһ����������ƣ�";
	for(int i=0;i<n;i++)
		in>>g.verticeslist[i];
	cout<<"������ߵ�������";
	in>>m;
	char ta,tb;
	int cost;
	for(i=0;i<m;i++)
	{
		cout<<"������ÿһ���ߵ����������Ȩֵ��";
		in>>ta>>tb>>cost;
		int pa=g.getvertexpos(ta);
		int pb=g.getvertexpos(tb);
		g.insertedge(pa,pb,cost);
	}
	return in;
}


ostream & operator << (ostream & out,graphmtx & g)//���ͼ����Ϣ
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