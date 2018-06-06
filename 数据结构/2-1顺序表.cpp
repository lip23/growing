#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int defaultsize=100;

class sqlist
{
private:
	int maxsize;
	int last;
	int * date;
	void resize(int newsize);
public:
	sqlist(int sz=defaultsize);//构造函数
	sqlist(sqlist & l);//复制构造函数
	~sqlist(){delete []date;}//析构函数
	int size()const{return maxsize;}//计算最大可容纳的表项个数
	int length()const{return last+1;}//计算表长度
	//int locate(int i)const;//
	int search(int & x)const;//搜索x在表中的位置
	bool getdate(int i,int & x)const;//取第i个表项的值
	void setdate(int i,int & x);//修改第i个表项的值
	bool insert(int i,int & x);//插入x在第i个表项之后
	bool remove(int i,int & x);//删除
	bool isempty();//判空
	bool isfull();//判满
	void input();//输入
	void output();//输出
	void suiji();
};

sqlist::sqlist(int sz)
{
	if(sz>0)
	{
		maxsize=sz;
		last=-1;
		date=new int [maxsize];
		if(date==NULL)
			cout<<"creat fail"<<endl;
		else
			cout<<"线性表构造成功"<<endl;
	}
}

sqlist::sqlist(sqlist & l)
{
	maxsize=l.size();
	last=l.length()-1;
	date=new int [maxsize];
	int t;
	for(int i=0;i<=last;i++)
	{
		l.getdate(i,t);
		date[i]=t;
	}
}

int sqlist::search(int & x)const
{
	for(int i=0;i<last;i++)
		if(date[i]==x)
			return i;
	return 0;
}

bool sqlist::getdate(int i,int & x)const
{
	if(i<1||i>last+1)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		x=date[i-1];
		return true;
	}
}

void sqlist::setdate(int i,int & x)
{
	if(i<1||i>last+1)
		cout<<" date erro"<<endl;
	else
		date[i]=x;
}

bool sqlist::insert(int i,int & x)
{
	if(i<1||i>last+2)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		for(int j=last+1;j>=i;j--)
			date[j]=date[j-1];
		date[i-1]=x;
		last++;
		return true;
	}
}

bool sqlist::remove(int i,int & x)
{
	if(i<1||i>last+1)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		i--;
		x=date[i];
		for(;i<last;i++)
			date[i]=date[i+1];
		last--;
		return true;
	}
}

bool sqlist::isempty()
{
	if(last==-1)
		return true;
	return false;
}

bool sqlist::isfull()
{
	if(last==maxsize-1)
		return true;
	return false;
}
	
void sqlist::input()
{
	cout<<"请输入您要输入的元素个数："<<endl;
	cin>>last;
	while(last<1||last>maxsize)
	{
		cout<<"您输入的元素有误，请重新输入："<<endl;
		cin>>last;
	}
	last--;
	cout<<"请输入您要输入的元素："<<endl;
	for(int i=0;i<=last;i++)
		cin>>date[i];
}

void sqlist::output()
{
	cout<<"当前表中有"<<last+1<<"个元素，分别为："<<endl;
	for(int i=0;i<=last;i++)
		cout<<setw(3)<<'['<<i+1<<']';
	cout<<endl;
	for(i=0;i<=last;i++)
		cout<<setw(5)<<date[i];
	cout<<endl;
}

void show()
{
		cout<<"///////////////////////////////////////////////////////////////////////"<<endl;
		cout<<"请输入您接下来要执行的操作："<<endl;
}

void sqlist::suiji()
{
	cout<<"请输入你要随机生成顺序表的大小"<<endl;
	cin>>last;
	while(last<1||last>maxsize)
	{
		cout<<"您输入的元素有误，请重新输入："<<endl;
		cin>>last;
	}
	last--;
	for(int i=0;i<=last;i++)
		date[i]=rand()%100;
}




int main()
{
	cout<<"**************顺序表的基本操作******************"<<endl;
	cout<<setw(8)<<" "<<"1,初始化一个线性表"<<endl;
	cout<<setw(8)<<" "<<"2,判断顺序表是否为空"<<endl;
	cout<<setw(8)<<" "<<"3,判断顺序表是否为满"<<endl;
	cout<<setw(8)<<" "<<"4,取第i个元素的值"<<endl;
	cout<<setw(8)<<" "<<"5,删除第i个元素"<<endl;
	cout<<setw(8)<<" "<<"6,在第i个元素之前插入一个元素"<<endl;
	cout<<setw(8)<<" "<<"7,输出线性表中的元素"<<endl;
    cout<<setw(8)<<" "<<"8,随机生成顺序表(元素为0--99之间)"<<endl;
    cout<<setw(8)<<" "<<"0,终止操作"<<endl;
	sqlist l;
	cout<<"************************************************"<<endl;
	int b;	
	cout<<"请输入您要执行的操作："<<endl;
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"操作终止"<<endl;
	case 1: 
		{
			l.input();
			show();
		}break;
	case 2:
		{
			if(l.isempty())
				cout<<"该顺序表为空"<<endl;
			else
				cout<<"该顺序表为非空"<<endl;
			show();
		}break;
	case 3: 
		{
			if(l.isfull())
				cout<<"该顺序表为满"<<endl;
			else
				cout<<"该顺序表为非满"<<endl;
			show();
		}break;
	case 4: 
		{
			int t,i;
			cout<<"请输入您要取的元素的位置："<<endl;
			cin>>i;
			if(l.getdate(i,t))
				cout<<"位置"<<i<<"的元素为："<<t<<endl;
			show();
		}break;
	case 5: 
		{
			int t,i;
			cout<<"请输入您要删除的元素的位置："<<endl;
			cin>>i;
			if(l.remove(i,t))
				cout<<"您要删除的元素是："<<t<<endl;
			show();
		}break;
	case 6: 
		{
			int t,i;
			cout<<"请输入您要插入的元素的位置："<<endl;
			cin>>i;
			cout<<"请输入您要插入的元素："<<endl;
			cin>>t;
			l.insert(i,t);
			show();
		}break;
	case 7:
		{
			l.output();
			show();
		}break;
	case 8:
		{
			l.suiji();
			show();
		}break;
	default:cout<<"您输入的数据有误，请重新输入："<<endl;
	};
	}while(b!=0);

	return 0;
}