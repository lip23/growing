#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	int x;
	int y;
	int c;
	node* link;
};

class queue
{
public:
	queue();
	~queue();
	void dequeue(int& x,int& y,int &c);
	void enqueue(int x,int y,int c);
	bool isempty();
	void display();
private:
	node * front;
	node * rear;
};

////////////////////////////////////////////////////////////

int main()
{
	queue q;
	char a[10][10];
	void set(char a[][10]);
	void show(char a[][10]);
	void show(int a[][10]);
	void trans(char a[][10],int b[][10]);
	set(a);
	show(a);
	int b[10][10];
	trans(a,b);
	static int x0,y0,x1,y1;
	cout<<"请输入起点X0,Y0：";
	cin>>x0>>y0;
	cout<<"请输入终点X1,Y1：";
	cin>>x1>>y1;
	void next(int a[10][10],int x0,int y0,int x1,int y1);
	next(b,x0,y0,x1,y1);
	//show(b);
	void min(int x0,int y0,int x1,int y1,char a[][10],int b[][10]);
	min(x0,y0,x1,y1,a,b);
	a[x0][y0]=2;
	a[x1][y1]=1;
	show(a);
	return 0;
}

//////////////////////////////////////////////////////////////////

void next(int a[10][10],int x0,int y0,int x1,int y1)
{
	a[x0][y0]=1;
	int c=1;
	queue q;
	void getnext(int x,int y,int c,int a[10][10],queue & q);
	getnext(x0,y0,c,a,q);
	while(!q.isempty())
	{
		q.dequeue(x0,y0,c);
		getnext(x0,y0,c,a,q);
		if(x0==x1&&y0==y1)
		{
			cout<<"最短路径是："<<endl;
			break;
		}
		if(q.isempty())
		{
			cout<<"无解"<<endl;
			break;
		}
	}
}

void getnext(int x,int y,int c,int a[10][10],queue & q)
{
	if(a[x][y+1]==0&&y+1<10)
	{
		a[x][y+1]=c+1;
		q.enqueue(x,y+1,c+1);
	}
	if(a[x][y-1]==0&&y-1>=0)
	{
		a[x][y-1]=c+1;
		q.enqueue(x,y-1,c+1);
	}
	if(a[x+1][y]==0&&x+1<10)
	{
		a[x+1][y]=c+1;
		q.enqueue(x+1,y,c+1);
	}
	if(a[x-1][y]==0&&x-1>=0)
	{
		a[x-1][y]=c+1;
		q.enqueue(x-1,y,c+1);
	}
}

/////////////////////////////////////////////////////////////////

void min(int x0,int y0,int x1,int y1,char a[][10],int b[][10])
{
	void getlast(int& x,int& y,int b[][10],char [][10]);
	while(x1!=x0||y1!=y0)
		getlast(x1,y1,b,a);
}

void getlast(int& x,int& y,int b[][10],char a[][10])
{
	if(x-1>=0&&b[x-1][y]==b[x][y]-1)
	{
		x--;
		a[x][y]=25;
	}
	else if(x+1<10&&b[x+1][y]==b[x][y]-1)
	{
		x++;
		a[x][y]=24;
	}
	else if(y-1>=0&&b[x][y-1]==b[x][y]-1)
	{
		y--;
		a[x][y]=26;
	}
	else if(y+1<10&&b[x][y+1]==b[x][y]-1)
	{
		y++;
		a[x][y]=27;
	}
}
		

/////////////////////////////////////////////////////////////////

queue::queue()
{
	front=new node;
	front->link=NULL;
	rear=front;
}

queue::~queue()
{
	while(front)
	{
		node * del=front;
		front=front->link;
		delete del;
	}
	//cout<<"析构成功"<<endl;
}

void queue::dequeue(int& x,int& y,int& c)
{
	if(!isempty())
	{
		node * del=front->link;
	    x=del->x;
	    y=del->y;
		c=del->c;
	    front->link=del->link;
	    delete del;
		if(!front->link)
			rear=front;
	}
	else
		cout<<"队空，操作有误"<<endl;
}

void queue::enqueue(int x,int y,int c)
{
	node * newnode=new node;
	newnode->x=x;
	newnode->y=y;
	newnode->c=c;
	newnode->link=rear->link;
	rear->link=newnode;
	rear=newnode;
}

bool queue::isempty()
{
	if(front==rear)
		return true;
	return false;
}

void queue::display()
{
	if(isempty())
		cout<<"队列已空"<<endl;
	else
	{
		node * cur=front->link;
		while(cur)
		{
			cout<<'('<<cur->x<<','<<cur->y<<','<<cur->c<<')'<<endl;
		    cur=cur->link;
		}
	}
}


///////////////////////////////////////////////////////////////////////


void set(char a[10][10])
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			a[i][j]=rand()%2*10+32;
}

void show(char a[10][10])
{
	cout<<setw(3)<<' ';
	for(int k=0;k<10;k++)
		cout<<setw(3)<<k;
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<setw(3)<<i;
		for(int j=0;j<10;j++)
			cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
	cout<<endl;
}

void trans(char a[10][10],int b[10][10])
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			if(a[i][j]==' ')
				b[i][j]=0;
			else
				b[i][j]=-1;
		}
}

void show(int a[10][10])
{
	cout<<setw(3)<<' ';
	for(int k=0;k<10;k++)
		cout<<setw(3)<<k;
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<setw(3)<<i;
		for(int j=0;j<10;j++)
			cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
	cout<<endl<<endl;
}