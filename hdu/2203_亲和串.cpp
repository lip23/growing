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
	string s1,s2;
	while(cin>>s1>>s2){
		int m=s1.size(),n=s2.size();
		if(m<n)cout<<"no\n";
		else{
			s1.append(s1);
			m*=2;
			int *next=new int[n];
        	nextarray(s1,n,next);
        	int k=0,p=0;
        	while(n-p<=m-k&&p<n){
            	if(s1[k]==s2[p]){
                	k++;
                	p++;
            	}
           	 	else{
                	p=next[p];
                	if(p==-1){p++;k++;}
            	} 
        	}
        	if(p==n)cout<<"yes\n";
        	else cout<<"no\n";
		}
	}
	return 0;
}
