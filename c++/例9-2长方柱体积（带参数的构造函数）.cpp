#include <iostream>
using namespace std;

class box
{
private:
	int length;
	int width;
	int higth;
	int v;
public:
	box(int ,int ,int);
	void set();
	void volume();
	void show();
};

box::box(int l,int w,int h)
{
	length=l;
	width=w;
	higth=h;
}

void box::set()
{
	cin>>length>>width>>higth;
}

void box::volume()
{
	v=length*width*higth;
}

void box::show()
{
	cout<<"volume="<<v<<endl;
}

int main()
{
	box b1(12,20,25);
	box b2(10,14,20);
	b1.volume();
	b2.volume();
	b1.show();
	b2.show();
	box b3(0,0,0);
	b3.set();
	b3.volume();
	b3.show();
	return 0;
}

