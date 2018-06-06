#include <iostream>
using namespace std;

class chang
{
private:
	int length;
	int width;
	int heigh;
	int v;
public:
	void input();
	void tiji();
	void show();
};

int main()
{
	chang c1,c2,c3;
	c1.input();
	c1.tiji();
	c1.show();
	c2.input();
	c2.tiji();
	c2.show();
	c3.input();
	c3.tiji();
	c3.show();
	return 0;
}

void chang::input()
{
	cout<<"please input length width heigh"<<endl;
	cin>>length>>width>>heigh;
}

void chang::tiji()
{
	v=length*width*heigh;
}

void chang::show()
{
	cout<<"v="<<v<<endl;
}

