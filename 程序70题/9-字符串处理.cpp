#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout<<"输入任意一个字符串s1，而后由s1形成另两个字符串s2和s3并显示在屏幕上。"<<endl;
	cout<<"其中s2是s1甩掉其尾部的所有非字母字符后得到的字符串，而s3则由s2甩掉其"<<endl;
	cout<<"前导的所有非字母字符后形成的字符串。例如，程序执行后的屏幕显示结果可为:"<<endl;
	cout<<"s1:36 262/x+y*z-a D007 END! %%% 60++=--!"<<endl;
	cout<<"s2=36 262/x+y*z-a D007 END"<<endl;
	cout<<"s3=x+y*z-a D007 END"<<endl;
	string s1,s2,s3;
	cout<<"****************************************************************************"<<endl;
	s1="36 262/x+y*z-a D007 END! %%% 60++=--!";
	int l;
	cout<<"s1= "<<s1<<endl;
	l=strlen(s1.c_str());
	for(int i=l-1;s1[i]<'A'||s1[i]>'z';)
		i--;
	s2=s1;
	s2[i+1]='\0';
	cout<<"s2= ";
	cout<<s2<<endl;
	for(i=0;s1[i]<'A'||s1[i]>'z';)
		i++;
	s3=s2;
	l=strlen(s2.c_str());
	for(int j=0;j<l;j++)
	{
		s3[j]=s2[j+i];
	}
	cout<<"s3= ";
	cout<<s3<<endl;
	return 0;
}
 