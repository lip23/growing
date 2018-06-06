#include <iostream>
using namespace std;

class array
{
private:
	int a[10];
	int m;
public:
	void set();
	void max();
	void show();
};


int main()
{
	array b;
	b.set();
	b.max();
	b.show();
	return 0;
}

void array::set()
{
	cout<<"请输入10个整数"<<endl;
	for(int i=0;i<10;i++)
		cin>>a[i];
}

void array::max()
{
	int k=0;
	for(int i=1;i<10;i++)
		if(a[k]<a[i])
			k=i;
	m=a[k];
}

void array::show()
{
	cout<<"最大数max="<<m<<endl;
}

