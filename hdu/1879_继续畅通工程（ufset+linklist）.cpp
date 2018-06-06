#include <stdio.h>
#include <string.h>

struct edge
{
    int v1;
    int v2;
    int w;
	int tag;
	edge* link;
};

class ufsets
{
public:
    ufsets(int n);
    ~ufsets();
	bool weightunion(int r1,int r2);
    int collapsingfind(int r);
private:
    int* parent;
};

class road
{
public:
	road();
	~road();
	void en(edge&);
	bool de(edge&);
private:
	edge* front;
};

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
		int m=n*(n-1)/2;
        ufsets u(n+1);
		road d;
		int count=0,cost=0;
        for(int i=0;i<m;i++)
		{
			edge temp;
			scanf("%d %d %d %d",&temp.v1,&temp.v2,&temp.w,&temp.tag);
			if(temp.tag)
			{
				if(u.weightunion(temp.v1,temp.v2))
					count++;
			}
			else
				d.en(temp);
		}
		edge temp;
		while(count!=n-1&&d.de(temp))
			if(u.weightunion(temp.v1,temp.v2))
			{
				count++;
				cost+=temp.w;
			}
		printf("%d\n",cost);
    }
    return 0;
}

road::road()
{
	front=new edge;
	front->link=NULL;
}

road::~road()
{
	while(front)
	{
		edge* del=front;
		front=front->link;
		delete del;
	}
}

void road::en(edge& e)
{
	edge* cur=front;
	while(cur->link&&e.w>cur->link->w)
		cur=cur->link;
	edge* nedge=new edge;
	nedge->v1=e.v1;
	nedge->v2=e.v2;
	nedge->w=e.w;
	//nedge->tag=e.tag;
	nedge->link=cur->link;
	cur->link=nedge;
}

bool road::de(edge& e)
{
	edge* cur=front->link;
	if(!cur)
		return false;
	e.v1=cur->v1;
	e.v2=cur->v2;
	e.w=cur->w;
	//e.tag=cur->tag;
	front->link=cur->link;
	delete cur;
	return true;
}

ufsets::ufsets(int n)
{
    parent=new int[n];
    memset(parent,-1,4*n);
}

ufsets::~ufsets()
{
	delete []parent;
}

bool ufsets::weightunion(int r1,int r2)
{
    int root1=collapsingfind(r1);
    int root2=collapsingfind(r2);
    int temp=parent[root1]+parent[root2];
    if(root1<root2)
    {
        parent[root1]=temp;
        parent[root2]=root1;
        return true;
    }
    else if(root2<root1)
    {
        parent[root2]=temp;
        parent[root1]=root2;
        return true;
    }
    return false;
}

int ufsets::collapsingfind(int r)
{
    for(int i=r;parent[i]>=0;i=parent[i]);
    while(r!=i)
    {
        int temp=parent[r];
        parent[r]=i;
        r=temp;

    }
    return i;
}