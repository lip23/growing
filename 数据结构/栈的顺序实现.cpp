#include <iostream.h>
#include <malloc.h>
typedef struct Sqstack//����ջ����������
{
	int *base;//ջ��ָ��
	int *top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ�
}stack;


void initstack(stack &s,int x)//����һ����ջs
{
	s.base=(int *)malloc(x+5 * sizeof(int));
	if(!s.base)
		cout<<"overflow";
	s.top=s.base;
	s.stacksize=x;
	cout<<"ջ��ʼ���ɹ�!"<<endl;
}


void creatstack(stack &s,int x)//ʵ����ջs
{
	for(int n=1;n<=x;n++)
		cin>>s.base[n];
	cout<<"�������ջ�������ǣ�"<<endl;
	for(int m=x;m>=1;m--)
		cout<<s.base[m]<<endl;
	s.top=&s.base[s.stacksize+1];
}


void gettop(stack s)//���ջ��Ԫ��
{
	cout<<*(s.top-1)<<endl;
}


void pushstack(stack &s,int m)//�����µ�ջ��Ԫ��m
{
	int n;
	s.stacksize++;
	s.top=&s.base[s.stacksize+1];
	s.base[s.stacksize]=m;
	cout<<"��ջ��������:"<<endl;
	for(n=s.stacksize;n>=1;n--)
		cout<<s.base[n]<<endl;
}


void deltopstack(stack &s)//ɾ��ջ��Ԫ��
{
	int n;
	int m;
	if(s.top==s.base)
		cout<<"overflow"<<endl;
	else
		n=*(s.top-1);
	cout<<n<<endl;
	s.stacksize--;
	cout<<"�µ�ջ�е�Ԫ���ǣ�"<<endl;
	for(m=s.stacksize;m>=1;m--)
		cout<<s.base[m]<<endl;
}


	


void main()
{
	int x;//ջ�Ĵ�С
	int e;
	stack s;
	cout<<"��������Ҫ�����ջ�Ĵ�С"<<endl;
	cin>>x;
	initstack(s,x);
	cout<<"������ջ�е�Ԫ��"<<endl;
	creatstack(s,x);
	cout<<"ջ��Ԫ���ǣ�  "<<endl;
	gettop(s);
	cout<<"��������Ҫ�²����Ԫ��e= ";
	cin>>e;
	pushstack(s,e);
	cout<<"Ҫɾ��ջ��Ԫ��e=  ";
	deltopstack(s);
}
