#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b){
		int hash[10];
		int data[10];
		memset(hash,-1,sizeof(hash));
		a=a%10;
		int temp=a;
		data[0]=a;
		hash[a]=0;
		int i;
		for(i=1;i<b;i++){
			a=(a*temp)%10;
			//cout<<"i="<<i<<endl;
			//cout<<"a="<<a<<endl;
			data[i]=a;
			//cout<<"hash="<<hash[a]<<endl;
			if(hash[a]>-1)break;
			hash[a]=i;
			//cout<<"hash="<<hash[a]<<endl;
		}
		//cout<<"i="<<i<<endl;
		if(i==b)cout<<data[i-1]<<endl;
		else{
			int pos=(b-1)%(i-hash[a])+hash[a];
			cout<<data[pos]<<endl;
		}
	}
	return 0;
}
