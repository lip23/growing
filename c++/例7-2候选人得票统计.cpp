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
	cout<<"三个候选人为 li zhang wang 请10个代表输入您要选者的候选人"<<endl;
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
	cout<<"li得票数是："<<l.count<<endl;
	cout<<"zhang得票数是："<<z.count<<endl;
	cout<<"wang得票数是："<<w.count<<endl;
	return 0;
}
