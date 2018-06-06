#include <iostream>
#include <iomanip>
using namespace std;

const int defaultsize=20;

class minheap
{
public:
	minheap(int sz=defaultsize);//构造函数：建立空堆
	minheap(int arr[],int n);//构造函数：通过一个数组建立
	~minheap();//析构函数
	bool insert(const int & x);//插入x
	bool remove(int & x);//删除堆顶上的最下元素
	bool isempty()const;//判空
	bool isfull()const;//判满
	void makeempty();//置空堆
	void show();
private:
	int * heap;//存放最小堆中元素的数组 
	int currentsize;//堆中当前元素个数
	int maxheapsize;//最小堆中当前元素
	void siftdown(int start,int m);//从start到m下滑调整成最小堆
	void siftup(int star);//从start到0上滑调整成最小堆
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
		cerr<<"堆存储分配失败"<<endl;
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
		cerr<<"堆存储分配失败"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
		heap[i]=arr[i];
	currentsize=n;
	cout<<"初始数据："<<endl;
	show();
	cout<<endl;
	siftup(n-1);
}

minheap::~minheap()
{
	delete []heap;
	cout<<endl<<"堆析构成功"<<endl;
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
		cout<<"该最小堆为空堆"<<endl;
	else
	{	
		/*deep=0,count=1;
		while(count-1<currentsize)
		{
			count*=2;
			deep++;
		}*/
		cout<<"该最小堆为："<<endl;
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




