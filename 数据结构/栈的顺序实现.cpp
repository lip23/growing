#include <iostream.h>
#include <malloc.h>
typedef struct Sqstack//定义栈的数据类型
{
	int *base;//栈底指针
	int *top;//栈顶指针
	int stacksize;//当前已分配的存储空间
}stack;


void initstack(stack &s,int x)//构造一个空栈s
{
	s.base=(int *)malloc(x+5 * sizeof(int));
	if(!s.base)
		cout<<"overflow";
	s.top=s.base;
	s.stacksize=x;
	cout<<"栈初始化成功!"<<endl;
}


void creatstack(stack &s,int x)//实例化栈s
{
	for(int n=1;n<=x;n++)
		cin>>s.base[n];
	cout<<"您构造的栈的序列是："<<endl;
	for(int m=x;m>=1;m--)
		cout<<s.base[m]<<endl;
	s.top=&s.base[s.stacksize+1];
}


void gettop(stack s)//输出栈顶元素
{
	cout<<*(s.top-1)<<endl;
}


void pushstack(stack &s,int m)//插入新的栈顶元素m
{
	int n;
	s.stacksize++;
	s.top=&s.base[s.stacksize+1];
	s.base[s.stacksize]=m;
	cout<<"新栈的序列是:"<<endl;
	for(n=s.stacksize;n>=1;n--)
		cout<<s.base[n]<<endl;
}


void deltopstack(stack &s)//删除栈顶元素
{
	int n;
	int m;
	if(s.top==s.base)
		cout<<"overflow"<<endl;
	else
		n=*(s.top-1);
	cout<<n<<endl;
	s.stacksize--;
	cout<<"新的栈中的元素是："<<endl;
	for(m=s.stacksize;m>=1;m--)
		cout<<s.base[m]<<endl;
}


	


void main()
{
	int x;//栈的大小
	int e;
	stack s;
	cout<<"请输入您要构造的栈的大小"<<endl;
	cin>>x;
	initstack(s,x);
	cout<<"请输入栈中的元素"<<endl;
	creatstack(s,x);
	cout<<"栈顶元素是：  "<<endl;
	gettop(s);
	cout<<"请输入你要新插入的元素e= ";
	cin>>e;
	pushstack(s,e);
	cout<<"要删除栈顶元素e=  ";
	deltopstack(s);
}
