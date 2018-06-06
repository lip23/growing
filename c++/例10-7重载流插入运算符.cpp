#include <iostream.h>

class complex
{
public:
	complex(int=0,int=0);
	void show();
	friend ostream & operator <<(ostream &,complex &);
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

int main()
{
	complex c1(8,6);
	c1.show();
	cout<<c1;
	return 0;
}


