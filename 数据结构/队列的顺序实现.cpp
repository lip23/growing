#include <iostream.h>
#include <malloc.h>
typedef struct //创建队列的线性存储结构
{
	int* elem;
	int size;
}sqqueue;


void initsqqueue(sqqueue &q,int n)//初始化大小为n的队列
{
	
	q.elem=(int*)malloc((n+10)*(sizeof(int)));
	if(!q.elem)
		cout<<"队列初始化失败"<<endl;
	q.size=n;
	cout<<"请输入初始化队列中的元素"<<endl;
	for(int i=1;i<=n;i++)
		cin>>q.elem[i];
	cout<<"队列初始化成功"<<endl;
}


void putout(sqqueue q)
{
	cout<<"当前队列中的元素是"<<endl;
		for(int i=1;i<=q.size;i++)
			cout<<q.elem[i]<<"  ";
}


void enqueue(sqqueue &q)//插入元素e为q的新队尾元素
{
	int e;
	cout<<endl<<"请输入您要入队的元素e=  ";
	cin>>e;
	cout<<endl;
	q.size++;
	q.elem[q.size]=e;
}


void dequeue(sqqueue &q)//若队列不空，则删除q的队头元素，用e返回其值
{
	int e;
	if(q.size==0)
	{
		cout<<"队列为空"<<endl;
	}
	else
	{
		e=q.elem[1];
		q.size--;
		cout<<"出队的元素e=  "<<e<<endl;
		for(int i=1;i<=q.size;i++)
			q.elem [i]=q.elem[i+1];
	}
}





void main()
{
	int n;
	char m;
	sqqueue q;
	cout<<"请输入您要创建的队列的大小n=  ";
	cin>>n;
	initsqqueue(q,n);
	putout(q);
	do
	{
		cout<<endl<<"请输入您要执行的操作 a元素入队  b元素出队  c终止操作"<<endl;
		cin>>m;
		if(m=='a')
		{
			enqueue(q);
			putout(q);
		}
		else if(m=='b')
		{
			dequeue(q);
			if(q.size==0)
			{
				cout<<"当前队列已空,操作终止"<<endl;
				m='c';
			}
			else
			{
				putout(q);
			}
		}
		else
			cout<<"您输入的数据有误，请重新输入"<<endl;
	}while(m!='c');
}
	
