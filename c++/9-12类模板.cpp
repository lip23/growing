#include <iostream>
using namespace std;

template <class T>

class date
{
public:
	date(T x,T y,T z);
	void display();
private:
	T a;
	T b;
	T c;
};

int main()
{
	date<int> d(2013,2,7);
	date<int> t(15,18,58);
	d.display();
	t.display();
	return 0;
}

template <class T>

date<T>::date(T x,T y,T z):a(x),b(y),c(z){};

template <class T>

void date<T>::display()
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}