#include <iostream>
using namespace std;
int main()
{
	bool sushu(int);
    int n;
    while(cin>>n)
    {
        for(int i=(n+1)/2;i<n;i++)
        {
			if(sushu(i))
			{
				for(int k=(n+1)/2;k>1;k--)
					if(sushu(k)&&k+i<=n)
						break;
				if(k+i==n)
				{
					cout<<k<<' '<<i<<endl;
					break;
				}
			}
        }
    }
    return 0;
}

bool sushu(int n)
{
    for(int k=2;k<n;k++)
		if(n%k==0)
			return false;
	return true;
}
