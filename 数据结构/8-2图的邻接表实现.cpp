#include <iostream>
using namespace std;

const int defaultver=16;//Ĭ����󶥵���
const int maxweight=-1;

struct edge//�߽ڵ�Ķ���
{
	int dest;//�ߵ���һ����λ��
	int cost;//�ߵ�Ȩֵ
	edge * link;//��һ������ָ��
};


struct vertex//����Ķ���
{
	char date;//��������
	edge * adj;//�������ͷָ��
};


class graphlnk//��Ȩ����ͼ
{
public:
	graphlnk(int sz=defaultver);//���캯��
	~graphlnk();//��������
	char getvalue(int i);//ȡ����i��ֵ
	int getweight(int v1,int v2);//ȡ��(v1��v2)��Ȩֵ
	int getfirstneighbor(int v);//ȡ����v�ĵ�һ���ڽӶ���
	int getnextneighbor(int v,int w);//ȡv���ڽӶ���w����һ�ڽӶ���
	bool insertvertex(const char & vertex);//���붥��vertex
	bool insertedge(int v1,int v2,int cost);//�����v1��v2��ȨֵΪcost
	bool removevertex(int v);//ɾ������v��������ı�
	bool removeedge(int v1,int v2);//��ͼ��ɾȥ��(v1,v2);
	//friend istream & operator >>(istream & in,graphmtx & g);//����ͼ����Ϣ
	//friend ostream & operator <<(ostream & out,graphmtx & g);//���ͼ����Ϣ
private:
	int numver;//��ǰ������
	int numed;//��ǰ����
	int maxver;//��ǰ��󶥵���
	vertex * nodetable;//�����
	int getvertexpos(const char vertex);//��������vertex��ͼ�е�λ��
};

int main()
{
	graphlnk g;
	return 0;
}


graphlnk::graphlnk(int sz)//���캯��
{
	maxver=sz;numver=0;numed=0;
	nodetable=new vertex[sz];
	if(!nodetable)
	{
		cerr<<"�ڴ����ʧ��"<<endl;
		exit(1);
	}
	for(int i=0;i<maxver;i++)
		nodetable[i].adj=NULL;
	cout<<"����ͼ����ɹ�"<<endl;
}


graphlnk::~graphlnk()//��������
{
	for(int i=0;i<numver;i++)
	{
		edge * temp=nodetable[i].adj;//ɾ����������Ľڵ�
		while(temp)
		{
			edge * del=temp;
			temp=temp->link;
			delete del;
		}
	}
	delete [] nodetable;//ɾ�����������
	cout<<"�����ɹ�"<<endl;
}


int graphlnk::getvertexpos(const char v)//��������vertex��ͼ�е�λ��
{
	for(int i=0;i<numver;i++)
		if(nodetable[i].date==v)
			return i;
	return -1;
}


char graphlnk::getvalue(int i)//ȡ����i��ֵ
{
	if(i<0||i>=numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return ' ';
	}
	return nodetable[i].date;
}

	
int graphlnk::getweight(int v1,int v2)//ȡ��(v1��v2)��Ȩֵ
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return -1;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(!temp)
		return -1;
	return temp->cost;
}

	
int graphlnk::getfirstneighbor(int v)//ȡ����v�ĵ�һ���ڽӶ���
{
	if(v<0||v>=numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return -1;
	}
	return nodetable[v].adj==NULL?-1:nodetable[v].adj->dest;
}

	
int graphlnk::getnextneighbor(int v,int w)//ȡv���ڽӶ���w����һ�ڽӶ���
{
	if(v<0||v>=numver||w<0||w>numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return -1;
	}
	edge * temp=nodetable[v].adj;
	while(temp&&temp->dest!=w)
		temp=temp->link;
	if(!temp||!temp->link)
		return -1;
	return temp->link->dest;
}


bool graphlnk::insertvertex(const char & vertex)//���붥��vertex
{
	if(numver==maxver)
		return false;
	nodetable[numver].date=vertex;
	nodetable[numver].adj=NULL;
	numver++;
	return true;
}

	
bool graphlnk::insertedge(int v1,int v2,int c)//�����v1��v2��ȨֵΪcost
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return false;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(temp)
	{
		cout<<"Ҫ����ı��Ѿ�����"<<endl;
		return false;
	}
	edge * newed=new edge;//����v1������
	newed->cost=c;
	newed->dest=v2;
	newed->link=nodetable[v1].adj;
	nodetable[v1].adj=newed;
	edge * newed2=new edge;//����v2������
	newed2->cost=c;
	newed2->dest=v1;
	newed2->link=nodetable[v2].adj;
	nodetable[v2].adj=newed2;
	numed++;
	return true;
}
	

bool graphlnk::removevertex(int v)//ɾ������v��������ı�
{
	if(v<0||v>=numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return true;
	}
	if(numver==1)
	{
		cout<<"ֻ��һ����㣬ɾ��ʧ��"<<endl;
		return false;
	}
	edge * del=nodetable[v].adj;//ɾ��ͷ���Ϊv1�ı�����
	while(del)
	{
		edge * d=del;
		del=del->link;
		delete d;
		numed--;
	}
	nodetable[v].adj=NULL;
	for(int i=0;i<numver;i++)//ɾ������ͷ����а���v�ı�
	{
		edge * p=nodetable[i].adj;
		edge * q;
		edge * s=p;
		while(p&&p->dest!=v)
		{
			q=p;
			p=p->link;
		}
		if(p)//�ñ������к���v�ı�
		{
			if(p==s){nodetable[i].adj=NULL;delete p;}//�ñ�������ֻ��һ����
			else{q->link=p->link;delete p;}
		}
	}
	if(v!=numver-1)//�
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
	

bool graphlnk::removeedge(int v1,int v2)//��ͼ��ɾȥ��(v1,v2);
{
	if(v1<0||v1>=numver||v2<0||v2>numver)
	{
		cout<<"�����λ�ô���"<<endl;
		return false;
	}
	edge * temp=nodetable[v1].adj;
	while(temp&&temp->dest!=v2)
		temp=temp->link;
	if(!temp)
	{
		cout<<"Ҫɾ���ı߲�����"<<endl;
		return false;
	}
	if(nodetable[v1].adj->dest==v2)//ɾ����<v1,v2>
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
	if(nodetable[v2].adj->dest==v1)//ɾ����<v2,v1>
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

