#include <iostream>
using namespace std;

class box
{
private:
	int len;
	int wid;
	int hig;
	int vol;
public:
	box(int=5,int=5,int=5);
	~box();
	void v();
};

int main()
{
	box b[4]={box(),box(10),box(10,15),box(10,15,20)};
	for(int i=0;i<4;i++)
		b[i].v();
	return 0;
}

box::box(int l,int w,int h):len(l),wid(w),hig(h){};

void box::v()
{
	vol=len*wid*hig;
	cout<<"v="<<vol<<endl;
}

box::~box()
{
	cout<<"destrory date"<<endl;
}
