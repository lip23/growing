#include <iostream>
using namespace std;
int main()
{
	cout<<"任意输入10个正整数，求出其中互不相同的数的个数num，以及此num个数中哪一个数的出现次数最多，共出现了几次。"<<endl;
	int a[10];
	int num=10,i;
	int m,max=0,p=0;
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(a[i]==a[j])
			{
				p++;
				if(p>max)
				{
					max=p;
					m=i;
				}
			}

		}
		if(p)
		{
			num--;
			p=0;
		}
	}
	max++;
	cout<<"互不相同的数的个数："<<num<<endl;
	cout<<"出现次数最多的是："<<a[m]<<endl;
	cout<<"出现的次数是："<<max<<endl;
	return 0;
}
