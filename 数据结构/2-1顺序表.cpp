#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int defaultsize=100;

class sqlist
{
private:
	int maxsize;
	int last;
	int * date;
	void resize(int newsize);
public:
	sqlist(int sz=defaultsize);//���캯��
	sqlist(sqlist & l);//���ƹ��캯��
	~sqlist(){delete []date;}//��������
	int size()const{return maxsize;}//�����������ɵı������
	int length()const{return last+1;}//�������
	//int locate(int i)const;//
	int search(int & x)const;//����x�ڱ��е�λ��
	bool getdate(int i,int & x)const;//ȡ��i�������ֵ
	void setdate(int i,int & x);//�޸ĵ�i�������ֵ
	bool insert(int i,int & x);//����x�ڵ�i������֮��
	bool remove(int i,int & x);//ɾ��
	bool isempty();//�п�
	bool isfull();//����
	void input();//����
	void output();//���
	void suiji();
};

sqlist::sqlist(int sz)
{
	if(sz>0)
	{
		maxsize=sz;
		last=-1;
		date=new int [maxsize];
		if(date==NULL)
			cout<<"creat fail"<<endl;
		else
			cout<<"���Ա���ɹ�"<<endl;
	}
}

sqlist::sqlist(sqlist & l)
{
	maxsize=l.size();
	last=l.length()-1;
	date=new int [maxsize];
	int t;
	for(int i=0;i<=last;i++)
	{
		l.getdate(i,t);
		date[i]=t;
	}
}

int sqlist::search(int & x)const
{
	for(int i=0;i<last;i++)
		if(date[i]==x)
			return i;
	return 0;
}

bool sqlist::getdate(int i,int & x)const
{
	if(i<1||i>last+1)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		x=date[i-1];
		return true;
	}
}

void sqlist::setdate(int i,int & x)
{
	if(i<1||i>last+1)
		cout<<" date erro"<<endl;
	else
		date[i]=x;
}

bool sqlist::insert(int i,int & x)
{
	if(i<1||i>last+2)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		for(int j=last+1;j>=i;j--)
			date[j]=date[j-1];
		date[i-1]=x;
		last++;
		return true;
	}
}

bool sqlist::remove(int i,int & x)
{
	if(i<1||i>last+1)
	{
		cout<<" date erro"<<endl;
		return false;
	}
	else
	{
		i--;
		x=date[i];
		for(;i<last;i++)
			date[i]=date[i+1];
		last--;
		return true;
	}
}

bool sqlist::isempty()
{
	if(last==-1)
		return true;
	return false;
}

bool sqlist::isfull()
{
	if(last==maxsize-1)
		return true;
	return false;
}
	
void sqlist::input()
{
	cout<<"��������Ҫ�����Ԫ�ظ�����"<<endl;
	cin>>last;
	while(last<1||last>maxsize)
	{
		cout<<"�������Ԫ���������������룺"<<endl;
		cin>>last;
	}
	last--;
	cout<<"��������Ҫ�����Ԫ�أ�"<<endl;
	for(int i=0;i<=last;i++)
		cin>>date[i];
}

void sqlist::output()
{
	cout<<"��ǰ������"<<last+1<<"��Ԫ�أ��ֱ�Ϊ��"<<endl;
	for(int i=0;i<=last;i++)
		cout<<setw(3)<<'['<<i+1<<']';
	cout<<endl;
	for(i=0;i<=last;i++)
		cout<<setw(5)<<date[i];
	cout<<endl;
}

void show()
{
		cout<<"///////////////////////////////////////////////////////////////////////"<<endl;
		cout<<"��������������Ҫִ�еĲ�����"<<endl;
}

void sqlist::suiji()
{
	cout<<"��������Ҫ�������˳���Ĵ�С"<<endl;
	cin>>last;
	while(last<1||last>maxsize)
	{
		cout<<"�������Ԫ���������������룺"<<endl;
		cin>>last;
	}
	last--;
	for(int i=0;i<=last;i++)
		date[i]=rand()%100;
}




int main()
{
	cout<<"**************˳���Ļ�������******************"<<endl;
	cout<<setw(8)<<" "<<"1,��ʼ��һ�����Ա�"<<endl;
	cout<<setw(8)<<" "<<"2,�ж�˳����Ƿ�Ϊ��"<<endl;
	cout<<setw(8)<<" "<<"3,�ж�˳����Ƿ�Ϊ��"<<endl;
	cout<<setw(8)<<" "<<"4,ȡ��i��Ԫ�ص�ֵ"<<endl;
	cout<<setw(8)<<" "<<"5,ɾ����i��Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"6,�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"7,������Ա��е�Ԫ��"<<endl;
    cout<<setw(8)<<" "<<"8,�������˳���(Ԫ��Ϊ0--99֮��)"<<endl;
    cout<<setw(8)<<" "<<"0,��ֹ����"<<endl;
	sqlist l;
	cout<<"************************************************"<<endl;
	int b;	
	cout<<"��������Ҫִ�еĲ�����"<<endl;
	do
	{
		cin>>b;
	switch(b)
	{
	case 0: cout<<"������ֹ"<<endl;
	case 1: 
		{
			l.input();
			show();
		}break;
	case 2:
		{
			if(l.isempty())
				cout<<"��˳���Ϊ��"<<endl;
			else
				cout<<"��˳���Ϊ�ǿ�"<<endl;
			show();
		}break;
	case 3: 
		{
			if(l.isfull())
				cout<<"��˳���Ϊ��"<<endl;
			else
				cout<<"��˳���Ϊ����"<<endl;
			show();
		}break;
	case 4: 
		{
			int t,i;
			cout<<"��������Ҫȡ��Ԫ�ص�λ�ã�"<<endl;
			cin>>i;
			if(l.getdate(i,t))
				cout<<"λ��"<<i<<"��Ԫ��Ϊ��"<<t<<endl;
			show();
		}break;
	case 5: 
		{
			int t,i;
			cout<<"��������Ҫɾ����Ԫ�ص�λ�ã�"<<endl;
			cin>>i;
			if(l.remove(i,t))
				cout<<"��Ҫɾ����Ԫ���ǣ�"<<t<<endl;
			show();
		}break;
	case 6: 
		{
			int t,i;
			cout<<"��������Ҫ�����Ԫ�ص�λ�ã�"<<endl;
			cin>>i;
			cout<<"��������Ҫ�����Ԫ�أ�"<<endl;
			cin>>t;
			l.insert(i,t);
			show();
		}break;
	case 7:
		{
			l.output();
			show();
		}break;
	case 8:
		{
			l.suiji();
			show();
		}break;
	default:cout<<"������������������������룺"<<endl;
	};
	}while(b!=0);

	return 0;
}