#include <iostream>
#include <iomanip>
using namespace std;

const int defaultsize=20;

class minheap
{
public:
	minheap(int sz=defaultsize);//���캯���������ն�
	minheap(int arr[],int n);//���캯����ͨ��һ�����齨��
	~minheap();//��������
	bool insert(const int & x);//����x
	bool remove(int & x);//ɾ���Ѷ��ϵ�����Ԫ��
	bool isempty()const;//�п�
	bool isfull()const;//����
	void makeempty();//�ÿն�
	void show();
private:
	int * heap;//�����С����Ԫ�ص����� 
	int currentsize;//���е�ǰԪ�ظ���
	int maxheapsize;//��С���е�ǰԪ��
	void siftdown(int start,int m);//��start��m�»���������С��
	void siftup(int star);//��start��0�ϻ���������С��
	bool cmpchg(int,int,int a[]);
};


int main()
{
	int a[8]={53,17,78,9,45,65,87,23};
	minheap h(a,8);
	h.show();
	return 0;
}


minheap::minheap(int sz)
{
	maxheapsize=(defaultsize<sz)?sz:defaultsize;
	heap=new int [maxheapsize];
	if(heap==NULL)
	{
		cerr<<"�Ѵ洢����ʧ��"<<endl;
		exit(1);
	}
	currentsize=0;
}


minheap::minheap(int arr[],int n)
{
	maxheapsize=(defaultsize<n)?n:defaultsize;
	heap=new int [maxheapsize];
	if(heap==NULL)
	{
		cerr<<"�Ѵ洢����ʧ��"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
		heap[i]=arr[i];
	currentsize=n;
	cout<<"��ʼ���ݣ�"<<endl;
	show();
	cout<<endl;
	siftup(n-1);
}

minheap::~minheap()
{
	delete []heap;
	cout<<endl<<"�������ɹ�"<<endl;
}

bool minheap::isempty()const
{
	return (currentsize==0)?true:false;
}

bool minheap::isfull()const
{
	return (currentsize==maxheapsize)?true:false;
}

void minheap::makeempty()
{
	currentsize=0;
}

void minheap::show()
{
	if(currentsize==0)
		cout<<"����С��Ϊ�ն�"<<endl;
	else
	{	
		/*deep=0,count=1;
		while(count-1<currentsize)
		{
			count*=2;
			deep++;
		}*/
		cout<<"����С��Ϊ��"<<endl;
		int temp=2;
		for(int j=0;j<currentsize;j++)
		{
			cout<<heap[j]<<"  ";
			if(j+2==temp){cout<<endl;temp*=2;}
		}
	}
}

void minheap::siftup(int i)
{
	while(i)
	{
		if(cmpchg(i,(i-1)/2,heap))
		{
			int t=i;
			while(2*t+1<=currentsize-1/*||2*t+2<=currentsize-1*/)
			{
				if(/*(2*t+1<=currentsize-1)&&*/cmpchg(2*t+1,t,heap))
					t=2*t+1;
				else if((2*t+2<=currentsize-1)&&cmpchg(2*t+2,t,heap))
					t=2*t+2;
				else
					break;
			}
		}
		i--;
	}
}


bool minheap::cmpchg(int x,int y,int t[])
{
	if(y>=0&&t[x]<t[y])
	{
		int temp=t[x];
		t[x]=t[y];
		t[y]=temp;
		//show();
		//cout<<endl;
		return true;
	}
	return false;
}




