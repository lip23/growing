#include <iostream.h>

class complex
{
public:
	complex(int a=0,int b=0):real(a),imag(b){};
	void display();
	friend complex operator +(complex,complex);
	friend complex operator +(complex,int);
	friend complex operator +(int,complex);
private:
	int real;
	int imag;
};

int main()
{
	complex c1(3,5),c2(6),c3,c4,c5;
	c3=c2+c1;
	c4=5+c3;
	c5=c4+9;
	c1.display();
	c2.display();
	c3.display();
	c4.display();
	c5.display();
	return 0;
}

complex operator +(complex a,complex b)
{
	return complex(a.real+b.real,a.imag+b.imag);
}

complex operator +(complex a,int b)
{
	return complex(a.real+b,a.imag);
}

complex operator +(int a,complex b)
{
	return complex(a+b.real,b.imag);
}

void complex::display()
{
	cout<<real<<"+"<<imag<<'i'<<endl;
}

