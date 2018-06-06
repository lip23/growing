#include <iostream>
using namespace std;

bool cmple(int a[1000],int b[1000])
{
    for(int i=999;i>=0;i--)
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
        char tp1[1000],tp2[1000];
        while(cin>>tp1>>tp2)
        {
			int p1=1,p2=1;
			int l1=strlen(tp1);
			int l2=strlen(tp2);
			if(tp1[0]=='-')
				p1=-1;
			if(tp2[0]=='-')
				p2=-1;
			int a[1000],b[1000],re[1000];
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(re,0,sizeof(re));
			int i=p1==1?0:1;
			for(;i<l1;i++)
				a[l1-1-i]=tp1[i]-48;
			//cout<<a[0]<<endl;
			i=p2==1?0:1;
			for(;i<l2;i++)
				b[l2-1-i]=tp2[i]-48;
			//cout<<b[0]<<endl;
			if(p1*p2==1)
			{
				for(int k=0;k<1000;k++)
				{
					re[k]+=a[k]+b[k];
					if(re[k]>=10)
					{
						re[k+1]++;
						re[k]-=10;
					}
				}
				for(k=999;re[k]==0&&k>=0;k--);
				//cout<<"k="<<k<<endl;
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
					for(int k=0;k<1000;k++)
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
					for(int k=0;k<1000;k++)
					{
						re[k]+=b[k]-a[k];
						if(re[k]<0)
						{
							re[k+1]--;
							re[k]+=10;
						}
					}
				}
				for(int k=999;re[k]==0&&k>=0;k--);
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