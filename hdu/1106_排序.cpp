#include <iostream>
#include <string>
using namespace std;
int main()
{
    string data;
	cin>>data;
	do
    {
        int i=0;
        int td[1000];
        memset(td,0,sizeof(td));
        int k=0;
		while(data[i]=='5')
			i++;
        while(data[i])
        {
            if(data[i]!='5')
            {
                td[k]=td[k]*10+data[i]-48;
                i++;
            }
            else
            {
                do
                {
                    i++;
                }while(data[i]=='5');
                k++;
            }
        }
        if(data[i-1]!='5')
          k++;
        for(i=0;i<k;i++)
        {
            int min=i;
            int temp;
            for(int j=i+1;j<k;j++)
                if(td[min]>td[j])
                    min=j;
            temp=td[i];
            td[i]=td[min];
            td[min]=temp;
            cout<<td[i];
			if(i!=k-1)
				cout<<' ';
        }
        cout<<endl;
    } while(cin>>data);
    return 0;
}