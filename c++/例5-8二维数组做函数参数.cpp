#include <iostream>
using namespace std;
int main()
{
	int a[3][4]={{11,32,45,67},{22,44,66,88},{15,72,43,37}};
	int max_value(int *);
	int max=0;
	max=max_value(&a[0][0]);
	cout<<"the max value is "<<max<<endl;
	return 0;
}


int max_value(int *p)
{
	int m;
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			if(*(p+4*i+j)>m)
				m=*(p+4*i+j);
	return m;
}