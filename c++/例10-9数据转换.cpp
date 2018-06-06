#include <iostream.h>

class complex
{
public:
	complex(int=0,int=0);
	void show();
	friend ostream & operator<<(ostream &,complex &);
	friend istream & operator>>(istream &,complex &);
	//operator double();
	friend complex operator+(complex & c1,complex & c2);
	complex(double);
private:
	int real;
	int imag;
};

complex operator+(complex & c1,complex & c2)
{
	c1.real+=c2.real;
	c1.imag+=c2.imag;
	return c1;
}

//complex::operator double()
//{
	//return real;
//}

complex::complex(int r,int i):real(r),imag(i){};

complex::complex(double a)
{
	real=int(a);
	imag=0;
}

void complex::show()
{
	cout<<real<<'+'<<imag<<'i'<<endl;
}

ostream & operator <<(ostream & output,complex & c)
{
	output<<c.real<<'+'<<c.imag<<'i'<<endl;
	return output;
}

istream & operator >>(istream & input,complex & c)
{
	input>>c.real>>c.imag;
	return input;
}

int main()
{
	complex c1(6,8);
	c1.show();
	complex c2(6,8);
	c1=c2+9.9;
	cout<<c1<<endl;;
	return 0;
}
