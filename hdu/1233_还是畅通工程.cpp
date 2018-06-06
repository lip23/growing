#include <iostream>
using namespace std;

struct edge
{
	int start;
	int end;
	int weight;
};

class ufsets
{
public:
	ufsets(int n);
	~ufsets(){delete []parent;}
	bool weightunion(int r1,int r2);
	int collapsingfind(int r);
private:
	int size;
	int* parent;
};

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int m=(n-1)*n/2;
		edge* e=new edge[m];
		ufsets u(n);
		for(int i=0;i<m;i++)
			cin>>e[i].start>>e[i].end>>e[i].weight;
		for(i=0;i<m-1;i++)
		{
			int min=i;
			for(int j=i+1;j<m;j++)
				if(e[min].weight>e[j].weight)
					min=j;
			edge temp=e[i];
			e[i]=e[min];
			e[min]=temp;
		}
		int k=1,count=0;
		for(i=0;k<n;i++)
		{
			if(u.weightunion(e[i].start-1,e[i].end-1))
			{
				count+=e[i].weight;
				k++;
			}
		}
		cout<<count<<endl;
		delete []e;
	}
	return 0;
}

ufsets::ufsets(int n)
{
	size=n;
	parent=new int[size];
	memset(parent,-1,4*size);
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
