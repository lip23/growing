#include <iostream>
using namespace std;

template <class T>

void myfuntpt(T*b,int n)
{
	int max=0,min=0,sum=0;
	for(int i=0;i<n;i++)
	{
		if(b[max]<b[i])
			max=i;
		if(b[min]>b[i])
			min=i;
		sum=sum+b[i];
	}
	cout<<"max="<<b[max]<<endl;
	cout<<"min="<<b[min]<<endl;
	cout<<"ave="<<sum/n<<endl;
}

int main()
{
	int a[10]={34,65,67,7,54,39,57,9,0,4};
	double b[10]={5.56,7.6,6.54,43.6,56.56,65.56,4.5,9.9,76,8.6};
	char c[10]={'a','r','g','s','r','y','u','w','i','j'};
	myfuntpt(a,10);
	myfuntpt(b,10);
	myfuntpt(c,10);
	return 0;
}


