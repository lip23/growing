#include <iostream>
using namespace std;
int main()
{
    int a,b,n;
    int f(int,int,int);
    cin>>a>>b>>n;
    while(a+b+n!=0)
    {
		int hash[7][7];
		memset(hash,0,sizeof(hash));
		for(int i=1;i<=n;i++)
			if(hash[f(a,b,i)][f(a,b,i+1)]==0)
			{
				//cout<<"hash["<<f(a,b,i)<<"]["<<f(a,b,i+1)<<"]="<<i<<endl;
				hash[f(a,b,i)][f(a,b,i+1)]=i;
				if(i==n)
					cout<<f(a,b,n)<<endl;
			}
			else
			{
				//cout<<"hash["<<f(a,b,i)<<"]["<<f(a,b,i+1)<<"]="<<i<<endl;
				int begain=hash[f(a,b,i)][f(a,b,i+1)];
				int times=i-begain;
				cout<<f(a,b,(n-begain)%times+begain)<<endl;
				break;
			}
        cin>>a>>b>>n;
    }
    return 0;
}

int f(int a,int b,int n)
{
    if(n==1||n==2)
        return 1;
    else
    {
        int t1=1,t2=1;
        for(int i=2;i<n;i++)
        {
            int t0=t2;
            t2=(a*t2+b*t1)%7;
            t1=t0;
        }
        return t2;
    }
}
