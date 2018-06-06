#include <iostream>
#include <algorithm>
using namespace std;

struct data
{
	double element;
	int indices;
};

bool cmp(data d1,data d2)
{
	return d1.element>d2.element;
}

bool cmp2(data d1,data d2)
{
	return d1.indices>d2.indices;
}

int main()
{
	int n,m,p;
	while(cin>>n>>m>>p){
		data *d=new data[m];
		for(int i=0;i<m;i++){
			d[i].element=0;
			d[i].indices=i+1;
		}
		for(i=0;i<n;i++)
			for(int j=0;j<m;j++){
				double temp;
				cin>>temp;
				d[j].element+=temp;
			}
		partial_sort(d,d+p,d+m,cmp);
		//stable_sort(d,d+m,cmp);
		//for(i=0;i<m;i++)
			//cout<<d[i].indices<<' '<<d[i].element<<endl;
		//for(int k=p;k<m;k++)
			//d[k].indices=0;
		sort(d,d+p,cmp2);
		for(int h=0;h<p;h++){
			cout<<d[h].indices;
			if(h!=p-1)
				cout<<' ';
		}
		cout<<endl;
		delete []d;
	}
	return 0;
}