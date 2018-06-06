//编写一个将x进制正整数化为10进制数并输出结果的函数，具有如下原型：void ChgxTo10(char a[], int x);
//参数a中放的是x进制正整数的各位数字字符（如x可为2或8或16等），要将其化为10进制数并输出。并编写主函数对它进行调用以验证其正确性。
//提示：注意检查a数组中x进制数的合法性。
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	int k;
	void chgxto10(string,int);
	cout<<"该程序可以转换36进制之内的数，9之后的后续数为大写字母A-Z"<<endl;
	cout<<"请输入数的进制："<<endl;
	cin>>k;
	cout<<"请输入一个数："<<endl;
	cin>>n;
	chgxto10(n,k);
	return 0;
}

void chgxto10(string n,int k)
{
	int m=1,p,l,t=0;
	l=strlen(n.c_str());
	for(int i=l-1;i>=0;i--)
	{
		if(k>=1&&k<=9)
			p=n[i]-48;
		else
			p=n[i]-55;
		t=t+p*m;
		m=m*k;
	}
	cout<<t<<endl;
}

