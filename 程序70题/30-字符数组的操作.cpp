// 编写具有如下原型的函数：void myFunc(char str1[], char str2[]);实现下述功能并输出所得结果：
//数组str1中出现了哪些字母（不区分大小写）? str1和str2两个数组中同时出现的字母（不区分大小写）有哪些?
//并编制主函数，调用myFunc以验证其正确性。
#include <iostream>
using namespace std;
int main()
{
	void myfunc(char s1[],char s2[]);
	char s1[30],s2[30];
	cout<<"请输入两个长度小于30的字符串:"<<endl;
	cin>>s1>>s2;
	myfunc(s1,s2);
	return 0;
}

void myfunc(char a[],char b[])
{
	void tongji(char t1[],char t2[]);
	char at2[26],bt2[26];
	cout<<"字符窜1中含有的字母："<<endl;
	tongji(a,at2);
	cout<<"字符窜2中含有的字母："<<endl;
	tongji(b,bt2);
	void same(char t1[],char t2[]);
	cout<<"两个字符串中都含有的字母："<<endl;
	same(at2,bt2);
}

void tongji(char a[],char b[])
{
	int c[26],i;
	char d[26][1]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(i=0;i<26;i++)
		c[i]=0;
	for(i=0;a[i];i++)
	{
		switch(a[i])
		{
		case'a':c[0]++;break;
		case'b':c[1]++;break;
		case'c':c[2]++;break;
		case'd':c[3]++;break;
		case'e':c[4]++;break;
		case'f':c[5]++;break;
		case'g':c[6]++;break;
		case'h':c[7]++;break;
		case'i':c[8]++;break;
		case'j':c[9]++;break;
		case'k':c[10]++;break;
		case'l':c[11]++;break;
		case'm':c[12]++;break;
		case'n':c[13]++;break;
		case'o':c[14]++;break;
		case'p':c[15]++;break;
		case'q':c[16]++;break;
		case'r':c[17]++;break;
		case's':c[18]++;break;
		case't':c[19]++;break;
		case'u':c[20]++;break;
		case'v':c[21]++;break;
		case'w':c[22]++;break;
		case'x':c[23]++;break;
		case'y':c[24]++;break;
		case'z':c[25]++;break;
		}
	}
	int j=0;
	for(i=0;i<26;i++)
		if(c[i])
		{
			b[j]=d[i][0];
			cout<<b[j]<<" ";
			j++;
		}
	cout<<endl;
	b[j]='\0';
}

void same(char a[],char b[])
{
	for(int i=0;a[i];i++)
	{
		for(int j=0;b[j];j++)
			if(a[i]==b[j])
			{
				b[j]='1';
				cout<<a[i]<<" ";
			}
	}
	cout<<endl;
}
