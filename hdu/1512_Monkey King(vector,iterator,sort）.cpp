#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class ufset
{
public:
    ufset(int);
    ~ufset();
    int cfind(int);
    bool wunion(int,int);
private:
    int* parent;
};


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ufset monkey(n+1);
		vector<int> v[
        for(int i=0;i<n;i++)
        {
            int temp;
            scanf("%d",&temp);
            monk[i].set(temp);
        }
        int m;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            int temp1,temp2;
            scanf("%d %d",&temp1,&temp2);
            if(!monkey.wunion(temp1-1,temp2-1))
                printf("%d\n",-1);
            else
                monk[temp1-1].qunion(monk[temp2-1]);

        }
    }
    return 0;
}



ufset::ufset(int n)
{
    parent=new int[n];
    for(int i=0;i<n;i++)
        parent[i]=-1;
}




ufset::~ufset()
{
    delete []parent;
}

int ufset::cfind(int n)
{
    for(int r=n;parent[r]>=0;r=parent[r]);
    while(parent[n]>=0)
    {
        int j=parent[n];
        parent[n]=r;
        n=j;
    }
    return r;
}

bool ufset::wunion(int r1,int r2)
{
    int root1=cfind(r1);
    int root2=cfind(r2);
    if(root1==root2)
        return false;
    int temp=parent[root1]+parent[root2];
    if(parent[root1]<parent[root2])
    {
        parent[root2]=root1;
        parent[root1]=temp;
    }
    else
    {
        parent[root1]=root2;
        parent[root2]=temp;
    }
    return true;
}