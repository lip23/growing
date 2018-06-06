#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
		int m,g;
		cin>>m>>g;
		int* point=new int[m];
		int* grade=new int[n];
		char** num=new char* [n];
		int* map=new int[n];
		int count=0;
		for(int i=0;i<m;i++)
			cin>>point[i];
		for(i=0;i<n;i++)
		{
			grade[i]=0;
			map[i]=0;
			num[i]=new char[20];
			cin>>num[i];
			int total;
			int temp;
			cin>>total;
			for(int j=0;j<total;j++)
			{	
				cin>>temp;
				grade[i]+=point[temp-1];
			}
			if(grade[i]>=g)
				count++;
		}
		cout<<count<<endl;
		for(i=0;i<count;i++)
		{
			int max=g-1;
			int pos;
			int j=0;
			for(j=0;j<n;j++)
			{
				if(map[j]!=1&&grade[j]>max)
				{
					max=grade[j];
					pos=j;
				}
				else if(map[j]!=1&&grade[j]==max&&max!=g-1&&strcmp(num[j],num[pos])<0)
					pos=j;
			}
			cout<<num[pos]<<' '<<grade[pos]<<endl;
			map[pos]=1;
		}
		for(i=0;i<n;i++)
			delete []num[i];
		delete []num;
		delete []grade;
		delete []point;
		delete []map;
		cin>>n;
	}
	return 0;
}