#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		__int64 temp;
		scanf("%I64d",&temp);
		__int64 m=1;
		while(temp&&temp%10==0)
		{
			m*=10;
			temp/=10;
		}
		__int64 data=0;
		while(temp)
		{
			data=data*10+temp%10;
			temp/=10;
		}
		printf("%I64d\n",data*m);
	}
	return 0;
}
