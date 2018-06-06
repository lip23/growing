#include <iostream>
using namespace std;
void f2(int& x2, int& t2);
void f1(int &x1, int &t1) 
{
	t1++;
	if (x1<88) 
	{
		x1+=10;	  
		f2(x1,t1);
	}
}

void f2(int& x2, int& t2) 
{
	cout<<"t2="<<t2<<endl;
	x2+=2;
	f1(x2, t2);
}

int main() 
{
	int x=63, n=22;
	f1(x,n);
	cout<<"n="<<n<<endl;
	cout<<"x="<<x<<endl;
	return 0;
}
