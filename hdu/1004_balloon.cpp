#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        char ** color;
        color=new char * [n];
        for(int i=0;i<n;i++)
        {
            color[i]=new char[15];
            cin>>color[i];
        }
        int pos=0,count=1;
        for(i=0;i<n-1;i++)
        {
            int temp=1;
            for(int k=i+1;k<n;k++)
                if(strcmp(color[i],color[k])==0)
                    temp++;
            if(count<temp)
            {
                count=temp;
                pos=i;
            }
        }
        cout<<color[pos]<<endl;
		for(i=0;i<n;i++)
			delete []color[i];
        delete []color;
        cin>>n;
    }
    return 0;
}
