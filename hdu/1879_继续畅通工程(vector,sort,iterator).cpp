#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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

bool cmp(edge e1,edge e2)
{
	return e2.w>e1.w;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int m=n*(n-1)/2;
        ufsets u(n+1);
		vector<edge> v;
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
                v.push_back(temp);
        }
		sort(v.begin(),v.end(),cmp);
		vector<edge>::iterator iter=v.begin();
        while(count!=n-1&&iter!=v.end())
		{
            if(u.weightunion(iter->v1,iter->v2))
            {
                count++;
                cost+=iter->w;
            }
			iter++;
		}
        printf("%d\n",cost);
    }
    return 0;
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