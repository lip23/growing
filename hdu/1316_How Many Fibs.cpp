#include <iostream>
#include <string>
using namespace std;
int main()
{
    
    char a[150],b[150];
    while(cin>>a>>b,a[0]!='0'||b[0]!='0')
	{
		int na[150],nb[150];
		memset(na,0,sizeof(na));
		memset(nb,0,sizeof(nb));
		int la=strlen(a);
		for(int i=0;a[i];i++)
			na[la-1-i]=a[i]-48;
		int lb=strlen(b);
		for(i=0;b[i];i++)
			nb[lb-1-i]=b[i]-48;
		//for(i=100;na[i]==0;i--);
		//for(;i>=0;i--)
			//cout<<na[i];
		//cout<<endl;
		//for(i=100;nb[i]==0;i--);
		//for(;i>=0;i--)
			//cout<<nb[i];
		//cout<<endl;
		int f(int a[101],int t[101]);
		int c=f(na,nb);
		cout<<c<<endl;
    }
    return 0;
}

int f(int a[150],int b[150])
{
	bool cmple(int a[150],int b[150]);
	int re[150];
	memset(re,0,sizeof(re));
	int tp1[150];
    int tp2[150];
    memset(tp1,0,sizeof(tp1));
    memset(tp2,0,sizeof(tp2));
	tp1[0]=1;
	tp2[0]=2;
	int c=0;
    if(cmple(b,tp1)&&cmple(tp1,a))
		c++;
	if(cmple(tp2,a)&&cmple(b,tp2))
		c++;
	re[0]=3;
	if(cmple(b,re))
    {
        int t1[150];
        int t2[150];
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        t1[0]=1;
        t2[0]=2;
        for(int i=3;cmple(b,re);i++)
        {  
			//cout<<"i="<<i<<endl;
            memset(re,0,sizeof(re));
            for(int j1=0;j1<150;j1++)
            {
                re[j1]+=t1[j1]+t2[j1];
                if(re[j1]>=10)
                {
                    re[j1]-=10;
                    re[j1+1]++;
                }
                t1[j1]=t2[j1];
                t2[j1]=re[j1];
            }
			//for(int k=100;re[k]==0;k--);
			//for(;k>=0;k--)
				//cout<<re[k];
			//cout<<endl;
			if(cmple(b,re)&&cmple(re,a))
				c++;
        } 
    }
	return c;
}

bool cmple(int a[150],int b[150])
{
	for(int i=100;i>=0;i--)
		if(a[i]<b[i])
		{
			//cout<<"a["<<i<<"]="<<a[i]<<endl;
			//cout<<"b["<<i<<"]="<<b[i]<<endl;
			return false;
		}
		else if(a[i]>b[i])
			return true;
	return true;
}