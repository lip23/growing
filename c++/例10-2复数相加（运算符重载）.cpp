#include <iostream>
using namespace std;

class complex
{
public:
	void show();
	complex( int=0,int=0);
	//friend complex operator +(complex,complex);
//private:
	int real;
	int imag;
};

complex operator +(complex a,complex b)
{
	complex c;
	c.real=a.real+b.real;
	c.imag=a.imag+b.imag;
	return c;
}

int main()
{
	complex c1(3,4),c2(5,-10),c3;
	c1.show();
	c2.show();
	c3=c2+c1;
	c3.show();
	return 0;
}

complex::complex(int a,int b):real(a),imag(b){};

void complex::show()
{
	if(imag>=0)
		cout<<real<<" + "<<imag<<'i'<<endl;
	if(imag<0)
		cout<<real<<" - "<<imag*(-1)<<'i'<<endl;
}