#include <iostream>
using namespace std;

class ufsets
{
public:
	ufsets(int n);
	~ufsets(){delete []parent;}
	void weightunion(int r1,int r2);
	int collapsingfind(int r);
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
			u.weightunion(a-1,b-1);
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

void ufsets::weightunion(int r1,int r2)
{
	int root1=collapsingfind(r1);
	int root2=collapsingfind(r2);
	int temp=parent[root1]+parent[root2];
	if(root1<root2)
	{
		parent[root1]=temp;
		parent[root2]=root1;
	}
	else if(root2<root1)
	{
		parent[root2]=temp;
		parent[root1]=root2;
	}
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

int ufsets::root()
{
	int count=0;
	for(int i=0;i<size;i++)
		if(parent[i]<0)
			count++;
	return count-1;
}






