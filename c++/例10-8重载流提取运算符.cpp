#include <iostream.h>

class complex
{
public:
	complex(int=0,int=0);
	void show();
	friend ostream & operator <<(ostream &,complex &);
	friend istream & operator >>(istream &,complex &);
private:
	int real;
	int imag;
};

complex::complex(int r,int i):real(r),imag(i){};

void complex::show()
{
	cout<<real<<'+'<<imag<<'i'<<endl;
}

ostream & operator << (ostream & output,complex & c)
{
	output<<c.real<<"+"<<c.imag<<'i'<<endl;
	return output;
}

istream & operator >> (istream & input,complex & c)
{
	cin>>c.real>>c.imag;
	return input;
}


int main()
{
	complex c1(8,6);
	c1.show();
	cout<<c1;
	complex c2;
	cin>>c2;
	cout<<c2;
	return 0;
}
