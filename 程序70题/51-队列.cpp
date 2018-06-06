//51． 队列是一种程序设计中常用的数据结构。它的结构和栈类似，但队列中的数据是先进先出。
//仿照7.1节对栈stack的定义，自定义一个队列类queue（队列中需要保存并处理的那一批同类型数据，也用一个数组来实现）。
//如，可设计私有数据成员如下：
//float data [maxsize];  		//data中存放队列的实际数据
//int front, rear; 	    		//元素放在data[front+1]到data[rear]之中
//其公有函数成员如下：
//queue（void）			//构造函数，置front=rear=-1，意味着队列为空
//～queue（void）			//析构函数
//bool Empty（void）		//判断队列是否为空
//bool Full（void）			//判断队列是否已满
//void Add（int a）			//往队列尾部加入一个数据
//float Delete（void）		//从队列首部取出一个数据

#include <iostream>
#include <iomanip>
using namespace std;

const int  maxsize=100;

class queue
{
public:
	queue();
	~queue();
	bool empty();
	bool full();
	void add(int a);
	int delet();
	void show();
private:
	int date[maxsize];
	int front,rear;
};

int main()
{
	queue q;
	int m;
	int a,d;
	do
	{
		cout<<"请选择您要执行的操作：1 插入，2 删除， 3 输出 4 判断队列空满 5 终止操作"<<endl;
		cin>>m;
		switch(m)
		{
		case 1:
			{
				cout<<"请输入您要插入的数："<<endl;
				cin>>a;
				q.add(a);
			}break;
		case 2:
			{
				d=q.delet();
				cout<<"您删除的队头元素为： "<<d<<endl;
			}break;
		case 3:q.show();break;
		case 4:
			{
				if(q.empty())
					cout<<"队列为空队列"<<endl;
				else if(q.full())
					cout<<"队列为满队列"<<endl;
				else
					cout<<"队列不空不满"<<endl;
			}break;
		case 5:break;
		default:cout<<"您输入的数据错误请重新输入"<<endl;
		}
	}while(m!=5);
	return 0;
}

queue::queue()
{
	front=rear=-1;
	cout<<"队列构造成功"<<endl;
}

queue::~queue()
{
	cout<<"队列成功析构"<<endl;
}

bool queue::empty()
{
	if(rear==front&&rear==-1)
		return true;
	return false;
}

bool queue::full()
{
	if(front==0&&rear==maxsize-1)
		return true;
	return false;
}

void queue::add(int a)
{
	rear++;
	date[rear]=a;
}

int queue::delet()
{
	int n=date[front+1];
	for(int i=0;i<rear;i++)
		date[i]=date[i+1];
	rear--;
	return n;
}

void queue::show()
{
	if(empty())
		cout<<"该队列为空列，没有元素"<<endl;
	else
	{
		cout<<"该队列中的元素有："<<endl;
		for(int i=0;i<=rear;i++)
		cout<<setw(4)<<date[i];
		cout<<endl;
	}
}
	

