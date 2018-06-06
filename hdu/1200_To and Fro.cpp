#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin>>n,n)
    {
        string temp;
        cin>>temp;
        for(int i=0;i<n;i++)
		{
			int k=i;
			bool p=true;
			while(k<temp.size())
				if(p)
				{
					//cout<<"pk1="<<k<<endl;
					cout<<temp[k];
					k=k+2*n-2*i-1;
					//cout<<"pk2="<<k<<endl;
					p=false;
				}
				else
				{
					//cout<<"k1="<<k<<endl;
					cout<<temp[k];
					k=k+2*i+1;
					//cout<<"k2="<<k<<endl;
					p=true;
				}
		}
        cout<<endl;
    }
    return 0;
}