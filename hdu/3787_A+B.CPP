#include <iostream>
#include <string>
using namespace std;

bool cmple(int a[11],int b[11])
{
    for(int i=10;i>=0;i--)
        if(a[i]<b[i])
        {
            return false;
        }
        else if(a[i]>b[i])
            return true;
    return true;
}

int main()
{
	char t1[20],t2[20];
	while(cin>>t1>>t2)
	{
		char tp1[11],tp2[11];
		for(int p=0,q=0;t1[p];p++)
			if(t1[p]!=',')
			{
				tp1[q]=t1[p];
				q++;
			}
		tp1[q]='\0';
		for(p=0,q=0;t2[p];p++)
			if(t2[p]!=',')
			{
				tp2[q]=t2[p];
				q++;
			}
		tp2[q]='\0';
		//cout<<tp1<<endl;
		//cout<<tp2<<endl;
        int p1=1,p2=1;
        int l1=strlen(tp1);
        int l2=strlen(tp2);
        if(tp1[0]=='-')
			p1=-1;
        if(tp2[0]=='-')
            p2=-1;
        int a[11],b[11],re[11];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(re,0,sizeof(re));
        int i=p1==1?0:1;
        for(;i<l1;i++)
			a[l1-1-i]=tp1[i]-48;
        i=p2==1?0:1;
        for(;i<l2;i++)
            b[l2-1-i]=tp2[i]-48;
        if(p1*p2==1)
        {
			for(int k=0;k<11;k++)
			{
				re[k]+=a[k]+b[k];
                if(re[k]>=10)
                {
					re[k+1]++;
                    re[k]-=10;
                }
            }
			for(k=10;re[k]==0&&k>=0;k--);
                if(p1==-1&&k>=0)
                    cout<<'-';    
            if(k==-1)
               cout<<0;
            for(k;k>=0;k--)
               cout<<re[k];
            cout<<endl;
        }
        else
        {
			int tp=false;
            if(cmple(a,b))
            {
               if(p1==-1)
					tp=true;
               for(int k=0;k<11;k++)
               {
					re[k]+=a[k]-b[k];
                    if(re[k]<0)
                    {
						re[k+1]--;
						re[k]+=10;
                    }
				}
			}
            else
            {
				if(p2==-1)
					tp=true;
				for(int k=0;k<11;k++)
                {
					re[k]+=b[k]-a[k];
                    if(re[k]<0)
                    {
						re[k+1]--;
                        re[k]+=10;
					}
                }
            }
            for(int k=10;re[k]==0&&k>=0;k--);
				if(tp&&k>=0)
                    cout<<'-';
            if(k==-1)
               cout<<0;
            for(k;k>=0;k--)
				cout<<re[k];
            cout<<endl;
		}
	}
    return 0;
}