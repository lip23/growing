#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

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
    }
};

int main()
{
    int n,c;
    int ca=0;
	bool cmp1(data,data);
	bool cmp2(data,data);
	bool cmp3(data,data);
    while(scanf("%d %d",&n,&c),n)
    {
        ca++;
        data* d=new data[n];
        for(int i=0;i<n;i++)
            scanf("%s %s %d",d[i].num,d[i].name,&d[i].grade);
        printf("Case %d:\n",ca);
        if(c==1)
			sort(d,d+n,cmp1);
        else if(c==2)
            sort(d,d+n,cmp2);
        else if(c==3)
			sort(d,d+n,cmp3);
		for(i=0;i<n;i++)
			d[i].show();
        delete []d;
    }
    return 0;
}

bool cmp1(data p1,data p2)
{
	return strcmp(p2.num,p1.num)>0?true:false;
}

bool cmp2(data p1,data p2)
{
	if(strcmp(p2.name,p1.name)!=0)
		return strcmp(p2.name,p1.name)>0?true:false;
	else
		return strcmp(p2.num,p1.num)>0?true:false;
}

bool cmp3(data p1,data p2)
{
	if(p1.grade!=p2.grade)
		return p2.grade>p1.grade;
	else
		return strcmp(p2.num,p1.num)>0?true:false;
}
