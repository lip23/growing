#include <stdio.h>
#include <math.h>

int main()
{
    bool hws(int);
    bool sushu(int);
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(b>9989899)
            b=9989899;
        for(int i=a;i<=b;i++)
            if(hws(i)&&sushu(i))
                printf("%d\n",i);
        printf("\n");
    }
    return 0;
}


bool hws(int n)
{
    if(n%2==0)
        return false;
    int t=n;
    int a=0;
    while(n)
    {
        a=a*10+n%10;
        n/=10;
    }
    if(a!=t)
        return false;
    return true;
    
}


bool sushu(int n)
{
    int m=(int)sqrt((double)n);
    for(int i=3;i<=m;i+=2)
        if(n%i==0)
            return false;
    return true;
}