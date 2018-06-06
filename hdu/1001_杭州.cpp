#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,l,r;
	while(scanf("%d %d %d %d",&n,&m,&l,&r),n||m||l||r)
	{
		int* result;
		result=new int[n];
		memset(result,0,4*n);
		int* temp=new int[n];
		memset(temp,0,4*n);
		temp[0]=1;
		for(int i=0;i<m;i++)
		{
			int w;
			scanf("%d",&w);
			for(int j=0;j<n;j++)
				if(temp[j])
				{
					int t=(j-w)%n;
					if(t<0)
						t+=n;
					result[(j+w)%n]+=temp[j];
					result[t]+=temp[j];
				}
			if(i!=m-1)
				for(int k=0;k<n;k++)
				{
					temp[k]=result[k];
					result[k]=0;
				}
		}
		if(m==0)
			result[0]=1;
		float total=0;
		for(int j=0;j<n;j++)
			total+=result[j];
		float sum=0;
		for(j=l-1;j<=r-1;j++)
			sum+=result[j];
		sum/=total;
		if(sum==1)
			printf("1\n");
		else if(sum==0)
			printf("0\n");
		else
			printf("%.4f\n",sum);
		delete []result;
		delete []temp;
	}
	return 0;
}
