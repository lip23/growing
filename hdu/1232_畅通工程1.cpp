#include <iostream>
using namespace std;

class ufsets
{
public:
	ufsets(int n);
	~ufsets(){delete []parent;}
	void weightunion(int r1,int r2);
	int collapsingfind(int r);
	void Union(int,int);
	int Find(int);
	int ufsets::root();
private:
	int size;
	int* parent;
};

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int m;
		cin>>m;
		ufsets u(n);
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			u.Union(a-1,b-1);
		}
		cout<<u.root()<<endl;
	}
	return 0;
}

ufsets::ufsets(int n)
{
	size=n;
	parent=new int[size];
	memset(parent,-1,4*size);
}

int ufsets::root()
{
	int count=0;
	for(int i=0;i<size;i++)
		if(parent[i]<0)
			count++;
	return count-1;
}

void ufsets::Union(int r1,int r2)
{
	int root1=Find(r1);
	int root2=Find(r2);
	if(root1!=root2)
	{
		parent[root1]+=parent[root2];
		parent[root2]=root1;
	}
}

int ufsets::Find(int r)
{
	for(int i=r;parent[i]>=0;i=parent[i]);
	return i;
}
