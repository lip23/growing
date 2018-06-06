#include <iostream>
using namespace std;

template <class T>

class compare
{
private:
	T x;
	T y;
public:
	compare(T a,T b):x(a),y(b){};

	T max()
	{
		return x>y?x:y;
	};

	T min()
	{
		return x<y?x:y;
	};
};

int main()
{
	compare <int> c1(5,7);
	cout<<"max="<<c1.max()<<endl;
	cout<<"min="<<c1.min()<<endl;
	compare <double> c2(6.7,3.3);
    cout<<"max="<<c2.max()<<endl;
	cout<<"min="<<c2.min()<<endl;
	compare <char> c3('d','a');
	cout<<"max="<<c3.max()<<endl;
	cout<<"min="<<c3.min()<<endl;
	return 0;
}

//compare::compare(T a,T b):x(a),y(b){};

/*T compare::max()
{
	return a>b?a:b;
}

T compare::min()
{
	return a<b?a:b;
}*/