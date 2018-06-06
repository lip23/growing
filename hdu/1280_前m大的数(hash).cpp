#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    do
    {
        int m;
        cin>>m;
		int c=m;
        int* datan=new int[n];
        int hash[10001];
		memset(hash,0,sizeof(hash));
        for(int i=0;i<n;i++)
		{
            cin>>datan[i];
			for(int j=i-1;j>=0;j--)
				hash[datan[i]+datan[j]]++;
		}
        delete []datan;
        for(i=10000;m>0;i--)
			if(hash[i]>0)
				do
				{
					cout<<i;
					if(m>1)
						cout<<' ';
					m--;
					hash[i]--;
				}while(hash[i]>0&&m>0);
		if(c>0)
			cout<<endl;
    }while(cin>>n);
    return 0;
}