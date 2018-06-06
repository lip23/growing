//#include <iostream>
#include <string.h>
#include <stdio.h>
//using namespace std;

struct data
{
	char num[7];
	char name[9];
	int grade;
	void cop(data& d)
	{
		strcpy(num,d.num);
		strcpy(name,d.name);
		grade=d.grade;
	}
	void show()
	{
		printf("%s %s %d\n",num,name,grade);
		//cout<<num<<' '<<name<<' '<<grade<<endl;
	}
};

int main()
{
	int n,c;
	int ca=0;
	while(scanf("%d %d",&n,&c),n)
	{
		ca++;
		data* d=new data[n];
		for(int i=0;i<n;i++)
			scanf("%s %s %d",d[i].num,d[i].name,&d[i].grade);

			//cin>>d[i].num>>d[i].name>>d[i].grade;
		//cout<<"Case "<<ca<<':'<<endl;
		printf("Case %d:\n",ca);
		if(c==1)
			for(int i=0;i<n;i++)
			{
				int min=i;
				for(int j=i+1;j<n;j++)
					if(strcmp(d[min].num,d[j].num)>0)
						min=j;
				d[min].show();
				d[min]=d[i];
			}
		else if(c==2)
			for(int i=0;i<n;i++)
			{
				int min=i;
				for(int j=i+1;j<n;j++)
					if(strcmp(d[min].name,d[j].name)>0)
						min=j;
					else if(strcmp(d[min].name,d[j].name)==0&&strcmp(d[min].num,d[j].num)>0)
						min=j;
				d[min].show();
				d[min]=d[i];
			}
		else if(c==3)
			for(int i=0;i<n;i++)
			{
				int min=i;
				for(int j=i+1;j<n;j++)
					if(d[min].grade>d[j].grade)
						min=j;
					else if(d[min].grade==d[j].grade&&strcmp(d[min].num,d[j].num)>0)
						min=j;
				d[min].show();
				d[min]=d[i];
			}
		delete []d;
	}
	return 0;
}




