#include <iostream.h>
#include <malloc.h>
typedef struct
{
	int* elem;
	int size;
}list;


void initlist(list &l,int n)//初始化大小为n的顺序表
{
	l.elem=(int*)malloc(n*(sizeof(int)));
	if(!l.elem)
		cout<<"顺序表初始化失败"<<endl;
	cout<<"初始化成功"<<endl;
	cout<<"请输入待查找的元素"<<endl;
	for(int i=1;i<=n;i++)
		cin>>l.elem[i];
	cout<<"待查找的元素是"<<endl;
	for(int m=1;m<=n;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
	l.size=n;
	cout<<"初始化成功！"<<endl;
}



void putoutlist(list l)
{
	int n=l.size;
	for(int m=1;m<=n;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
}




void paixu(list &l)//用起泡法将待查元素排序
{
	int m;
	for(int n=l.size;n>1;n--)
		for(int i=1;i<n;i++)
		{
			if(l.elem[i]>l.elem[i+1])
			{
				m=l.elem[i+1];
				l.elem[i+1]=l.elem[i];
				l.elem[i]=m;
			}
		}
}




void midsearch(list l,int e)//在l中查找关键字为e的元素
{
	int low=1;
	int high=l.size;
	int mid=(low+high)/2;
	while(low<=high)
	{
		if(e<l.elem[mid])
		{
			high=mid-1;
			mid=(low+high)/2;
		}
		else if(e>l.elem[mid])
		{
			low=mid+1;
			mid=(low+high)/2;
		}
		else
		{
			cout<<"要查找的关键字的位置i=  "<<mid<<endl;
			break;
		}
	}
	if(low>high)
		cout<<"您要查找的关键字不在这个顺序表中!"<<endl;
}





void main()
{
	char a;
	int n;
	list l;
	cout<<"请输入待查找元素的个数n=  ";
	cin>>n;
	cout<<endl;
	initlist(l,n);
	cout<<"排序后的序列是"<<endl;
	paixu(l);
	putoutlist(l);
	cout<<"请输入您要查找的关键字e=  ";
	cin>>n;
	cout<<endl;
	midsearch(l,n);
	cout<<"您是否还继续查找  y代表是，n代表否"<<endl;
	cin>>a;
	while(a=='y')
		{
			cout<<"请输入您要查找的关键字e=  ";
			cin>>n;
			cout<<endl;
			midsearch(l,n);
			cout<<"是否继续"<<endl;
			cin>>a;
		}
	cout<<"查找终止";
}
