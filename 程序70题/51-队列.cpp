//51�� ������һ�ֳ�������г��õ����ݽṹ�����Ľṹ��ջ���ƣ��������е��������Ƚ��ȳ���
//����7.1�ڶ�ջstack�Ķ��壬�Զ���һ��������queue����������Ҫ���沢�������һ��ͬ�������ݣ�Ҳ��һ��������ʵ�֣���
//�磬�����˽�����ݳ�Ա���£�
//float data [maxsize];  		//data�д�Ŷ��е�ʵ������
//int front, rear; 	    		//Ԫ�ط���data[front+1]��data[rear]֮��
//�乫�к�����Ա���£�
//queue��void��			//���캯������front=rear=-1����ζ�Ŷ���Ϊ��
//��queue��void��			//��������
//bool Empty��void��		//�ж϶����Ƿ�Ϊ��
//bool Full��void��			//�ж϶����Ƿ�����
//void Add��int a��			//������β������һ������
//float Delete��void��		//�Ӷ����ײ�ȡ��һ������

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
		cout<<"��ѡ����Ҫִ�еĲ�����1 ���룬2 ɾ���� 3 ��� 4 �ж϶��п��� 5 ��ֹ����"<<endl;
		cin>>m;
		switch(m)
		{
		case 1:
			{
				cout<<"��������Ҫ���������"<<endl;
				cin>>a;
				q.add(a);
			}break;
		case 2:
			{
				d=q.delet();
				cout<<"��ɾ���Ķ�ͷԪ��Ϊ�� "<<d<<endl;
			}break;
		case 3:q.show();break;
		case 4:
			{
				if(q.empty())
					cout<<"����Ϊ�ն���"<<endl;
				else if(q.full())
					cout<<"����Ϊ������"<<endl;
				else
					cout<<"���в��ղ���"<<endl;
			}break;
		case 5:break;
		default:cout<<"����������ݴ�������������"<<endl;
		}
	}while(m!=5);
	return 0;
}

queue::queue()
{
	front=rear=-1;
	cout<<"���й���ɹ�"<<endl;
}

queue::~queue()
{
	cout<<"���гɹ�����"<<endl;
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
		cout<<"�ö���Ϊ���У�û��Ԫ��"<<endl;
	else
	{
		cout<<"�ö����е�Ԫ���У�"<<endl;
		for(int i=0;i<=rear;i++)
		cout<<setw(4)<<date[i];
		cout<<endl;
	}
}
	

