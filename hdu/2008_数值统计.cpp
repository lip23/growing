#include <iostream>
#include <algorithm>
#include <vector>

bool pn(double t){
	return t<0;
}

bool pz(double t){
	return t==0;
}

bool pp(double t){
	return t>0;
}

using namespace std;
int main()
{
	int n;
	while(cin>>n,n){
		vector<double> vec;
		for(int i=0;i<n;i++){
			double temp;
			cin>>temp;
			vec.push_back(temp);
		}
		cout<<count_if(vec.begin(),vec.end(),pn)<<' '
			<<count_if(vec.begin(),vec.end(),pz)<<' '
			<<count_if(vec.begin(),vec.end(),pp)<<endl;
			
	}
	return 0;
}
