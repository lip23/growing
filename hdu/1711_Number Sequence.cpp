#include <iostream>
using namespace std;

void nextarray(int *s,int c,int *next){
	next[0]=-1;
	for(int i=1;i<c;i++){
		int k=next[i-1];
		while(k!=-1&&s[k]!=s[i-1])k=next[k];
		next[i]=k+1;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		int *seq=new int[m];
		int *sub=new int[n];
		for(int i=0;i<m;i++)
			cin>>seq[i];
		for(int i=0;i<n;i++)
			cin>>sub[i];
		int *next=new int[n];
		nextarray(sub,n,next);
		int k=0,p=0;
		while(k<m&&p<n){
			if(seq[k]==sub[p]){
				k++;
				p++;
			}
			else{
				p=next[p];
				if(p==-1){
					p++;
					k++;
				}
			}	
		}
		if(p==n)cout<<k+1-n<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
