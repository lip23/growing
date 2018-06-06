#include <iostream>
using namespace std;
int main()
{
	int n;
	void horizontal(int,int,char);
	void vetical(int,int,int,char);
	cin>>n;
	for(int t=0;t<n;t++)
	{
		int m;
		char c;
		cin>>c>>m;
		int up=(m-3)/2;
		int down=2*up==m-3?up:up+1;
		int hw=down;
		int vw=m/6+1;
		horizontal(vw,hw,c);
		vetical(up,hw,vw,c);
		horizontal(vw,hw,c);
		vetical(down,hw,vw,c);
		horizontal(vw,hw,c);
		if(t!=n-1)
			cout<<endl;
	}
	return 0;
}

void horizontal(int vw,int hw,char c)
{
	cout.width(vw);
	cout.fill(' ');
	cout<<' ';
	cout.fill(c);
	cout.width(hw);
	cout<<c<<endl;
}

void vetical(int ud,int hw,int vw,char c)
{
	for(int i=0;i<ud;i++)
	{
		cout.fill(c);
		cout.width(vw);
		cout<<c;
		cout.fill(' ');
		cout.width(hw);
		cout<<' ';
		cout.fill(c);
		cout.width(vw);
		cout<<c<<endl;
	}
}
