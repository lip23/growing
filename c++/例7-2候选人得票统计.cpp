#include <iostream>
#include <string>
using namespace std;

struct hxr
{
	string name;
};

hxr h[10];


struct ct
{
	int count;
};

ct l={0},z,w;

int main()
{
	//l.count=0;
    z.count=0;
    w.count=0;
	int i;
	cout<<"������ѡ��Ϊ li zhang wang ��10������������Ҫѡ�ߵĺ�ѡ��"<<endl;
	for(i=0;i<10;i++)
		cin>>h[i].name;
	for(i=0;i<10;i++)
	{
		if(h[i].name=="li")
			l.count++;
		else if(h[i].name=="zhang")
			z.count++;
		else if(h[i].name=="wang")
			w.count++;
	}
	cout<<"li��Ʊ���ǣ�"<<l.count<<endl;
	cout<<"zhang��Ʊ���ǣ�"<<z.count<<endl;
	cout<<"wang��Ʊ���ǣ�"<<w.count<<endl;
	return 0;
}
