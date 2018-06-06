#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class cirqueue
{
public:
	cirqueue();
	~cirqueue();
	bool push(T&);
	bool pop(T&);
	bool getfront(T&);
	bool isempty();
	bool isfull();
	void show();
	void suiji();
	void makeempty();
private:
	T * elem;
	int front;
	int rear;
	int maxsize;
};

void show()
{
	cout<<"请输入您接下来要执行的操作：";
}

int main()
{
	cout<<"***************************循环队列的基本操作***************************"<<endl;
	cout<<setw(8)<<" "<<"1,进队"<<endl;
	cout<<setw(8)<<" "<<"2,出队"<<endl;
	cout<<setw(8)<<" "<<"3,输出队列头元素"<<endl;
	cout<<setw(8)<<" "<<"4,将队列置空"<<endl;
	cout<<setw(8)<<" "<<"5,判断队空"<<endl;
	cout<<setw(8)<<" "<<"6,判断队满"<<endl;
	cout<<setw(8)<<" "<<"7,输出队中元素"<<endl;
	cout<<setw(8)<<" "<<"8,随即生成一个队列"<<endl;
    cout<<setw(8)<<" "<<"0,终止操作"<<endl;
	cout<<"************************************************"<<endl;
	cirqueue<int> q;
	int b;	
	cout<<"请输入您要执行的操作：";
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"操作终止"<<endl;break;
	case 1: 
		{
			cout<<"请输入您要进队的元素：";
			int x;
			cin>>x;
			if(!q.push(x))
				cout<<"队满，操作失败"<<endl;
			show();
		}break;
	case 2:
		{
			int x;
			if(q.pop(x))
				cout<<"出队的元素是："<<x<<endl;
			else
				cout<<"操作失败"<<endl;
			show();
		}break;
	case 3: 
		{
			int x;
			if(q.getfront(x))
				cout<<"队列头元素元素是："<<x<<endl;
			else
				cout<<"操作失败"<<endl;
			show();
		}break;
	case 4: 
		{
			q.makeempty();
			show();
		}break;
	case 5: 
		{
			if(q.isempty())
				cout<<"该队列为空"<<endl;
			else
				cout<<"该队列为非空"<<endl;
			show();
		}break;
	case 6: 
		{
			if(q.isfull())
				cout<<"该队列为满"<<endl;
			else
				cout<<"该队列为非满"<<endl;
			show();
		}break;
	case 7:
		{
			if(q.isempty())
				cout<<"队空，操作失败"<<endl;
			else
				q.show();
			show();
		}break;
	case 8:
		{
			q.suiji();
			show();
		}break;
	default:cout<<"您输入的数据有误，请重新输入："<<endl;
	};
	}while(b!=0);
	return 0;
}

template <class T>
cirqueue<T>::cirqueue()
{
	cout<<"请输入你要创建的循环队列的大小：";
	cin>>maxsize;
	elem=new T[maxsize];
	if(elem==NULL)
	{
		cout<<"存储分配失败"<<endl;
		exit(1);
	}
	front=rear=0;
	cout<<"队列初始化成功!"<<endl;
}

template <class T>
cirqueue<T>::~cirqueue()
{
	delete [] elem;
	cout<<"循环队列析构成功"<<endl;
}

template <class T>
void cirqueue<T>::suiji()
{
	rear=maxsize-1;
	for(int i=0;i<rear;i++)
		elem[i]=rand()%100;
}

template <class T>
void cirqueue<T>::show()
{
	if(front<rear)
		for(int i=front;i<rear;i++)
			cout<<elem[i]<<"  ";
	else
	{
		for(int i=front;i<maxsize;i++)
			cout<<elem[i]<<"  ";
		for(i=0;i<rear;i++)
			cout<<elem[i]<<"  ";
	}
	cout<<endl;
}

template<class T>
bool cirqueue<T>::isempty()
{
	if(front==rear)
		return true;
	return false;
}

template <class T>
bool cirqueue<T>::isfull()
{
	if((rear+1)%maxsize==front)
		return true;
	return false;
}

template <class T>
bool cirqueue<T>::push(T &x)
{
	if(isfull())
		return false;
	elem[rear]=x;
	rear=(rear+1)%maxsize;
	return true;
}

template <class T>
bool cirqueue<T>::pop(T &x)
{
	if(isempty())
		return false;
	x=elem[front];
	front=(front+1)%maxsize;
	return true;
}

template <class T>
bool cirqueue<T>::getfront(T &x)
{
	if(isempty())
		return false;
	x=elem[front];
	return true;
}

template <class T>
void cirqueue<T>::makeempty()
{
	front=rear=0;
}


