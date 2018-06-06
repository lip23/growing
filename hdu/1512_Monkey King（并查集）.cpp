#include <stdio.h>
//#include <iostream>
//using namespace std;



class ufset
{
public:
	ufset(int);
	~ufset();
	int cfind(int);
	bool wunion(int,int);
	//void show();
private:
	int* parent;
	int* strval;
	int size;
};

/*void ufset::show()
{
	for(int i=0;i<size;i++)
		cout<<parent[i]<<"  ";
	cout<<endl;
	for(i=0;i<size;i++)
		cout<<strval[i]<<"  ";
	cout<<endl;
}*/

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ufset monkey(n);
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int temp1,temp2;
			scanf("%d %d",&temp1,&temp2);
			if(!monkey.wunion(temp1-1,temp2-1))
				printf("%d\n",-1);
		}
	}
	return 0;
}


ufset::ufset(int n)
{
	parent=new int[n];
	strval=new int[n];
	//memset(parent,-1,4*n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&strval[i]);
		parent[i]=-1;
	}
	size=n;
}




ufset::~ufset()
{
	delete []parent;
	delete []strval;
	//cout<<"delete succeed"<<endl;
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
	int max1=r1,max2=r2;
	//int temp1=r1,temp2=r2;
	for(int i=0;i<size;i++)
		if(parent[i]==root1&&strval[i]>=strval[r1])
		{
			max1=r1;
			r1=i;
			/*if(strval[temp1]<=strval[i])
			{
				max1=temp1;
				temp1=i;
			}*/
			//max1=r1;
			//cout<<"max1="<<max1<<endl;
			//cout<<"r1="<<r1<<endl;
		}
		else if(parent[i]==root2&&strval[i]>=strval[r2])
		{
			max2=r2;
			r2=i;
			//max2=r2;
			/*if(strval[i]>=strval[r2])
				
			if(strval[temp2]<=strval[i])
			{
				max2=temp2;
				temp2=i;
			}*/
			//cout<<"max2="<<max2<<endl;
			//cout<<"r2="<<r2<<endl;
		}
	strval[r1]/=2;
	strval[r2]/=2;
	max1=strval[max1]>=strval[max2]?max1:max2;
	r1=strval[r1]>=strval[r2]?r1:r2;
	/*for(i=0;i<size;i++)
		if(parent[i]==root1&&strval[i]>strval[max1])
				max1=i;
		else if(parent[i]==root2&&strval[i]>strval[max2])
				max2=i;*/
	max1=strval[max1]>=strval[r1]?max1:r1;
	printf("%d\n",strval[max1]);
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
	//show();
	return true;
}
