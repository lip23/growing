#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	int x;
	int y;
	char d;
	node* link;
};

class stack
{
public:
	stack();
	~stack();
	void push(int,int,int);
	void pop(int&,int&);
	void pop(int&,int&,char&);
	bool empty();
	void display();
private:
	node * top;
};

stack::stack()
{
	top=new node;
	top->link=NULL;
}

void stack::display()
{
	node * cur=top->link;
	int i=0;
	while(cur)
	{
		i++;
		cout<<'('<<cur->x<<','<<cur->y<<')'<<"  ";
		cur=cur->link;
		if(i%6==0)
			cout<<endl;
	}
	cout<<endl;
}


stack::~stack()
{
	node * del;
	while(top)
	{
		del=top;
		top=top->link;
		delete del;
	}
}

void stack::push(int a,int b,int c)
{
	node * newnode=new node;
	newnode->x=a;
	newnode->y=b;
	newnode->d=c;
	newnode->link=top->link;
	top->link=newnode;
}

void stack::pop(int& a,int& b)
{
	if(empty())
		cout<<"栈空，操作失败"<<endl;
	else
	{
		top=top->link;
		a=top->x;
		b=top->y;
	}
}

void stack::pop(int& a,int& b,char& c)
{
	if(empty())
		cout<<"栈空，操作失败"<<endl;
	else
	{
		top=top->link;
		a=top->x;
		b=top->y;
		c=top->d;
	}
}

bool stack::empty()
{
	if(top->link)
		return false;
	return true;
}

static bool tag2=false;

int main()
{
	char a[20][20];
	void set(char a[][20]);
	void show(char a[][20]);
	void cpy(char a[][20],char b[][20]);
	set(a);
	show(a);
	char b[20][20];
	cpy(a,b);
	int x0,y0,x1,y1;
	cout<<"请输入起点X0,Y0：";
	cin>>x0>>y0;
	cout<<"请输入终点X1,Y1：";
	cin>>x1>>y1;
	a[x0][y0]=2;
	a[x1][y1]=1;
	show(a);
	void next(int,int,int,int,char b[20][20]);
	next(x0,y0,x1,y1,b);
	if(tag2)
	{
		b[x0][y0]=2;
	    b[x1][y1]=1;
	    show(b);
	}
	return 0;
}

void next(int x,int y,int x1,int y1,char a[20][20])
{
	static stack s;
	bool tag=true;
	if(a[x][y+1]==' '&&y+1<20)
	{
		s.push(x,y,26);
		a[x][y]=26;
		y++;
	}
	else if(a[x][y-1]==' '&&y-1>=0)
	{
		s.push(x,y,27);
		a[x][y]=27;
		y--;
	}
	else if(a[x-1][y]==' '&&x-1>=0)
	{
		s.push(x,y,30);
		a[x][y]=30;
		x--;
	}
	else if(a[x+1][y]==' '&&x+1<20)
	{
		s.push(x,y,31);
		a[x][y]=31;
		x++;
	}
	else
	{
		a[x][y]='*';
		if(!s.empty())
			s.pop(x,y);
		else
		{
			cout<<"此迷宫无解"<<endl;
			tag=false;
		}
	}
	if((x!=x1||y!=y1)&&tag)
		next(x,y,x1,y1,a);
	else if(x==x1&&y==y1&&tag)
	{
		cout<<"此迷宫的解为："<<endl;
		s.display();
		tag2=true;
	}
}



void set(char a[20][20])
{
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			a[i][j]=rand()%2*10+32;
}

void show(char a[20][20])
{
	cout<<setw(3)<<' ';
	for(int k=0;k<20;k++)
		cout<<setw(3)<<k;
	cout<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<setw(3)<<i;
		for(int j=0;j<20;j++)
			cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
}

void cpy(char a[20][20],char b[20][20])
{
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			b[i][j]=a[i][j];
}



