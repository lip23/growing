#include <iostream>
using namespace std;

class box
{
private:
	int len;
	int wid;
	int hig;
public:
	static int vol;
	box(int=10,int=10,int=10);
	void v();
};

int main()
{
	box a(5,10,15);
	box b;
	a.v();
	cout<<"vol="<<box::vol<<endl;
	b.v();
	cout<<"vol="<<b.vol<<endl;
	box c(6,8,10);
	box * d;
	d=&c;
	d->v();
	cout<<"vol="<<d->vol<<endl;
	return 0;
}

int box::vol=0;

box::box(int l,int w,int h):len(l),wid(w),hig(h){};

void box::v()
{
	vol=hig*len*wid;
}
