#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        int *sodier=new int[m];
        memset(sodier,0,m*sizeof(sodier));
        int count=m;
        int t=2;
        int tt=2;
        int pos=0;
        int po=1;
        if(count>3){
        	while(1){
            	for(pos;;pos++){
                	if(pos==m)
                    	break;
                	if(!sodier[pos]){
                    	t--;
                    	if(!t)break;
                	}
            	}
            	if(count<=3&&pos==m)
                	break;
            	if(!t){
                	sodier[pos]=true;
                	count--;
                	t=tt;
            	}
            	else{
                	pos=0;
                	tt+=po;
                	t=tt;
                	po*=-1;
            	}
        	}
        }
        for(int i=0;i<m;i++){
            if(!sodier[i]){
                cout<<i+1;
                if(--count)cout<<' ';
            }
        }
        cout<<endl;
        delete []sodier;
    }
    return 0;
}