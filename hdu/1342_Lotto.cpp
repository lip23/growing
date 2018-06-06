#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	int n;
	int p=0;
	while(cin>>n,n){
		if(p)cout<<endl;
		int *data=new int[n];
		for(int i=0;i<n;i++)
			cin>>data[i];
		sort(data,data+n,less<int>());
		for(int m1=0;m1<n-5;m1++)
			for(int m2=m1+1;m2<n-4;m2++)
				for(int m3=m2+1;m3<n-3;m3++)
					for(int m4=m3+1;m4<n-2;m4++)
						for(int m5=m4+1;m5<n-1;m5++)
							for(int m6=m5+1;m6<n-0;m6++)
								cout<<data[m1]<<' '<<data[m2]<<' '<<data[m3]
								<<' '<<data[m4]<<' '<<data[m5]<<' '
								<<data[m6]<<endl;
		p++;
		delete []data;
	}
	return 0;
}
