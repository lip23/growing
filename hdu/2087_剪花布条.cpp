#include <iostream>
#include <string>
using namespace std;

void nextarray(string &s,int c,int *next){
    next[0]=-1;
    for(int i=1;i<c;i++){
        int k=next[i-1];
        while(k!=-1&&s[k]!=s[i-1])k=next[k];
        next[i]=k+1;
    }
}

int main()
{
	string seq;
    while(cin>>seq,seq!="#"){
        string sub;
        cin>>sub;
        int m=seq.size();
        int n=sub.size();
        int *next=new int[n];
        nextarray(sub,n,next);
        int k=0,p=0,count=0;
        while(k<m){
            if(seq[k]==sub[p]){
                k++;
                p++;
            }
            else{
                p=next[p];
                if(p==-1){p++;k++;}
			}
			if(p==n){
				count++;
				p=0;
			}    
        }
        cout<<count<<endl;
    }
    return 0;
}
