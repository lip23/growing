#include <iostream>
using namespace std;
int main()
{
    int i;
    cin>>i;
    for(int k=0;k<i;k++)
    {
        int n,m,t=1;
        cin>>n>>m;
        while(!(n==0&&m==0))
        {
            int c=0;
            for(int a=1;a<n;a++)
                for(int b=a+1;b<n;b++)
                    if((a*a+b*b+m)%(a*b)==0)
                        c++;
            cout<<"Case "<<t<<": "<<c<<endl;
            t++;
            cin>>n>>m;
        }
		if(k!=i-1)
			cout<<endl;
    }
    return 0;
}