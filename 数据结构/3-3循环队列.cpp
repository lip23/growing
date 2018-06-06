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
	cout<<"��������������Ҫִ�еĲ�����";
}

int main()
{
	cout<<"***************************ѭ�����еĻ�������***************************"<<endl;
	cout<<setw(8)<<" "<<"1,����"<<endl;
	cout<<setw(8)<<" "<<"2,����"<<endl;
	cout<<setw(8)<<" "<<"3,�������ͷԪ��"<<endl;
	cout<<setw(8)<<" "<<"4,�������ÿ�"<<endl;
	cout<<setw(8)<<" "<<"5,�ж϶ӿ�"<<endl;
	cout<<setw(8)<<" "<<"6,�ж϶���"<<endl;
	cout<<setw(8)<<" "<<"7,�������Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"8,�漴����һ������"<<endl;
    cout<<setw(8)<<" "<<"0,��ֹ����"<<endl;
	cout<<"************************************************"<<endl;
	cirqueue<int> q;
	int b;	
	cout<<"��������Ҫִ�еĲ�����";
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"������ֹ"<<endl;break;
	case 1: 
		{
			cout<<"��������Ҫ���ӵ�Ԫ�أ�";
			int x;
			cin>>x;
			if(!q.push(x))
				cout<<"����������ʧ��"<<endl;
			show();
		}break;
	case 2:
		{
			int x;
			if(q.pop(x))
				cout<<"���ӵ�Ԫ���ǣ�"<<x<<endl;
			else
				cout<<"����ʧ��"<<endl;
			show();
		}break;
	case 3: 
		{
			int x;
			if(q.getfront(x))
				cout<<"����ͷԪ��Ԫ���ǣ�"<<x<<endl;
			else
				cout<<"����ʧ��"<<endl;
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
				cout<<"�ö���Ϊ��"<<endl;
			else
				cout<<"�ö���Ϊ�ǿ�"<<endl;
			show();
		}break;
	case 6: 
		{
			if(q.isfull())
				cout<<"�ö���Ϊ��"<<endl;
			else
				cout<<"�ö���Ϊ����"<<endl;
			show();
		}break;
	case 7:
		{
			if(q.isempty())
				cout<<"�ӿգ�����ʧ��"<<endl;
			else
				q.show();
			show();
		}break;
	case 8:
		{
			q.suiji();
			show();
		}break;
	default:cout<<"������������������������룺"<<endl;
	};
	}while(b!=0);
	return 0;
}

template <class T>
cirqueue<T>::cirqueue()
{
	cout<<"��������Ҫ������ѭ�����еĴ�С��";
	cin>>maxsize;
	elem=new T[maxsize];
	if(elem==NULL)
	{
		cout<<"�洢����ʧ��"<<endl;
		exit(1);
	}
	front=rear=0;
	cout<<"���г�ʼ���ɹ�!"<<endl;
}

template <class T>
cirqueue<T>::~cirqueue()
{
	delete [] elem;
	cout<<"ѭ�����������ɹ�"<<endl;
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


