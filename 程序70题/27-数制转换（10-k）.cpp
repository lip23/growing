// 编写一个将10进制正整数n化为x进制数并输出结果的函数（如x可为2或8或16等），具有如下原型：
//void Chg10Tox(int n, int x);并编写主函数对它进行调用来验证其正确性。

#include <iostream>
using namespace std;
int main()
{
	cout<<"该程序可以转换36进制之内的数，9之后的后续数为大写字母A-Z"<<endl;
	void chg10tox(int n,int x);
	int n,x;
	cout<<"请输入一个任意正整数："<<endl;
	cin>>n;
	cout<<"请输入您要转换成的进制："<<endl;
	cin>>x;
	chg10tox(n,x);
	return 0;
}

void chg10tox(int n,int x)
{
	char p[20];
	int t;
	for(int i=0;n;i++)
	{
		t=n%x;
		n=(n-t)/x;
		if(t>=0&&t<=9)
			p[i]=t+48;
		else
			p[i]=t+65-10;
	}
	for(i=i-1;i>=0;i--)
		cout<<p[i];
	cout<<endl;
}

