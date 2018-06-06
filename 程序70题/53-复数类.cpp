#include <iostream.h>
#include <math.h>

class complex
{
private:
	double real;
	double imag;
public:
	complex(double=0,double=0);
	double qumo();
	friend istream & operator >>(istream &,complex &);
	friend ostream & operator <<(ostream &,complex &);
	friend complex operator +(complex &,complex &);
	friend complex operator -(complex &,complex &);
	friend complex operator *(complex &,complex &);
	friend complex operator /(complex &,complex &);
};

int main()
{
	complex c1,c2,c3;
	cin>>c1;
	cin>>c2;
	c3=c1+c2;
	cout<<c3;
	c3=c1-c2;
	cout<<c3;
	c3=c1*c2;
	cout<<c3;
	c3=c1/c2;
	cout<<c3;
	cin>>c3;
	cout<<c3.qumo()<<endl;;
	return 0;
}

complex::complex(double r,double i):real(r),imag(i){}

ostream & operator <<(ostream & output,complex &c)
{
	output<<c.real<<'+'<<c.imag<<'i'<<endl;
	return output;
}

istream & operator >>(istream & input,complex &c)
{
	cout<<"please input real imag:"<<endl;
	input>>c.real>>c.imag;
	return input;
}

complex operator +(complex & c1,complex & c2)
{
	return complex(c1.real+c2.real,c1.imag+c2.imag);
}

complex operator -(complex & c1,complex & c2)
{
	return complex(c1.real-c2.real,c1.imag-c2.imag);
}

complex operator *(complex & c1,complex & c2)
{
	return complex(c1.real*c2.real,c1.imag*c2.imag);
}

complex operator /(complex & c1,complex & c2)
{
	return complex(c1.real/c2.real,c1.imag/c2.imag);
}

double complex::qumo()
{
	return double(sqrt(real*real+imag*imag));
}


 
