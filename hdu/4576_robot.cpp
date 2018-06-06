#include <stdio.h>
#include <string.h>
int main()
{
    int n,m,l,r;
    while(scanf("%d %d %d %d",&n,&m,&l,&r),n||m||l||r)
    {
        double* result=new double[n];
        memset(result,0,n*sizeof(double));
        double* temp=new double[n];
        memset(temp,0,n*sizeof(double));
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
                    result[(j+w)%n]+=temp[j]*0.5;
                    result[t]+=temp[j]*0.5;
                }
            if(i!=m-1)
			{
				memcpy(temp,result,n*sizeof(double));
				memset(result,0,n*sizeof(double));
			}
        }
        if(m==0)
            result[0]=1;
		double sum=0;
        for(int j=l-1;j<=r-1;j++)
            sum+=result[j];
        printf("%.4lf\n",sum);
        delete []result;
        delete []temp;
    }
    return 0;
}