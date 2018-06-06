#include <iostream>
#include <iomanip>
using namespace std;

struct linknode
{
	int date;
	linknode * link;
	linknode(linknode*p=NULL){link=p;}
	linknode(const int &d,linknode*p=NULL):link(p),date(d){};
};

class linklist
{
private:
	linknode * first;
public:
	linklist();
	linklist(const int & x);
	linklist(linklist & l);
	~linklist(){makeempty();}
	void makeempty();
	int length()const;
	linknode* gethead()const {return first;}
	linknode* search(int x);
	linknode* locate(int i);
	bool getdate(int i,int &x);
	void setdate(int i,int& x);
	bool insert(int i,int & x);
	bool remove(int i,int & x);
	bool isempty()const;
	bool isfull()const;
	void sort();
	void input();
	void output();
	void suiji();
};

linklist::linklist()
{
	first=new linknode;
	first->link=NULL;
}

linklist::linklist(const int & x)
{
	first=new linknode(x);
}

int linklist::length()const
{
	linknode * cur=first;
	for(int i=0;cur->link;i++)
		cur=cur->link;
	return i;
}

linknode* linklist::locate(int i)                                          //��λ����i��λ��
{
	linknode * cur=first;
	for(int j=0;j<i;j++)
	{
		cur=cur->link;
		if(cur==NULL)
		{
			cout<<" date erro "<<endl;
			return NULL;
			exit(1);
		}
	}
	return cur;
}

linknode* linklist::search(int x)
{
	linknode * cur=first;
	while(cur->link)
	{
		if(cur->date==x)
			return cur;
	}
	return NULL;
}


void linklist::setdate(int i,int& x)                               //�޸�Ԫ��ֵ
{
	linknode * cur;
	cur=locate(i);
	cur->date=x;
}


bool linklist::getdate(int i,int &x)                              //ȡ��i��Ԫ��
{
	linknode * cur;
	if(locate(i))
	{
		cur=locate(i);
	    x=cur->date;
	    return true;
	}
	return false;
}

bool linklist::insert(int i,int & x)                            //����Ԫ��
{
	linknode * cur;
	cur=locate(i-1);
	if(cur)
	{
		linknode * newnode;
		newnode=new linknode(x);
		newnode->link=cur->link;
		cur->link=newnode;
		return true;
	}
	else
		return false;
}
	
bool linklist::remove(int i,int & x)                           //ɾ��Ԫ��
{
	linknode * cur;
	cur=locate(i-1);
	if(cur)
	{
		linknode * del;
		del=cur->link;
		cur->link=del->link;
		x=del->date;
		delete del;
		return true;
	}
	else
		return false;
}


bool linklist::isempty()const
{
	if(first->link==NULL)
		return true;
	else
		return false;
}

bool linklist::isfull()const
{

	return false;
}


void linklist::sort()
{
	linknode * cur1=first;
	linknode * cur2;
	int temp;
	int l=length();
	for(int i=0;i<l;i++)
	{
		cur1=cur1->link;
		cur2=cur1;
		for(int j=i+1;j<l;j++)
		{
			cur2=cur2->link;
			if(cur1->date>cur2->date)
			{
				temp=cur1->date;
				cur1->date=cur2->date;
				cur2->date=temp;
			}
		}
	}
}


void linklist::input()
{
	cout<<"��������Ҫ����ڵ�ĸ�����";
	int n;
	cin>>n;
	cout<<"������Ѱ�����뷽����a ǰ�巨�� b ��巨";
	char p;
	cin>>p;
	while(p!='a'&&p!='b')
	{
		cout<<"������Ĳ����������������룺";
		cin>>p;
	}
	linknode * cur=first;
	linknode * newnode;
	cout<<"��������Ҫ��������ݣ�"<<endl;
	if(p=='b')
	{
		for(int i=0;i<n;i++)
		{
			newnode=new linknode;
		    cin>>newnode->date;
		    newnode->link=cur->link;
		    cur->link=newnode;
		    cur=newnode;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			newnode=new linknode;
		    cin>>newnode->date;
		    newnode->link=cur->link;
		    cur->link=newnode;
		}
	}
}


void linklist::output()
{
	if(isempty())
		cout<<"�õ������ѿ�"<<endl;
	else
	{
		linknode* cur;
	    cur=first;
	    int l=length();
	    for(int i=1;i<=l;i++)
			cout<<setw(3)<<'['<<i<<']';
	    cout<<endl;
	    while(cur->link)
		{
			cur=cur->link;
		    cout<<setw(5)<<cur->date;
		}
	    cout<<endl;
	}
}

void linklist::suiji()
{
	cout<<"��������Ҫ����ڵ�ĸ�����";
	int n;
	cin>>n;
	linknode * cur=first;
	linknode * newnode;
	for(int i=0;i<n;i++)
	{
		newnode=new linknode;
		newnode->date=rand()%100+10;
		newnode->link=cur->link;
		cur->link=newnode;
	}
}

void linklist::makeempty()                                         //���������ÿ�
{
	linknode * cur;
	while(first->link)
	{
		cur=first;
		first=cur->link;
		delete cur;
	}
}

void show()
{
		cout<<"///////////////////////////////////////////////////////////////////////"<<endl;
		cout<<"��������������Ҫִ�еĲ�����";
}

int main()
{
	cout<<"***************************������Ļ�������***************************"<<endl;
	cout<<setw(8)<<" "<<"1,��ʼ��һ��������"<<endl;
	cout<<setw(8)<<" "<<"2,��������е�Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"3,�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"4,ȡ��i��Ԫ�ص�ֵ"<<endl;
	cout<<setw(8)<<" "<<"5,ɾ����i��Ԫ��"<<endl;
	cout<<setw(8)<<" "<<"6,�жϵ������Ƿ�Ϊ��"<<endl;
	cout<<setw(8)<<" "<<"7,�жϵ������Ƿ�Ϊ��"<<endl;
    cout<<setw(8)<<" "<<"8,������ɵ�����(Ԫ��Ϊ0--99֮��)"<<endl;
	cout<<setw(8)<<" "<<"9,�Ե������������"<<endl;
	cout<<setw(8)<<" "<<"10,�޸ĵ�i��Ԫ�ص�ֵ"<<endl;
	cout<<setw(8)<<" "<<"11,ȡ��i��Ԫ�ص�ֵ"<<endl;
	cout<<setw(8)<<" "<<"12,���������ÿ�"<<endl;
    cout<<setw(8)<<" "<<"0,��ֹ����"<<endl;
	linklist l;
	cout<<"************************************************"<<endl;
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
			l.input();
			show();
		}break;
	case 2:
		{
			l.output();
			show();
		}break;
	case 3: 
		{
			int t,i;
			cout<<"��������Ҫ�����Ԫ�ص�λ�ã�"<<endl;
			cin>>i;
			cout<<"��������Ҫ�����Ԫ�أ�"<<endl;
			cin>>t;
			l.insert(i,t);
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
			if(l.isfull())
				cout<<"�õ�����Ϊ��"<<endl;
			else
				cout<<"�õ�����Ϊ����"<<endl;
			show();
		}break;
	case 7:
		{
			if(l.isempty())
				cout<<"�õ�����Ϊ��"<<endl;
			else
				cout<<"�õ�����Ϊ�ǿ�"<<endl;
			show();
		}break;
	case 8:
		{
			l.suiji();
			show();
		}break;
	case 9:
		{
			l.sort();
			show();
		}break;
	case 10:
		{
			int i,x;
			cout<<"��������Ҫ�޸�Ԫ�ص�λ�ã�";
			cin>>i;
			if(i<=l.length())
			{
				cout<<"��������Ҫ�޸ĵ�ֵ��";
			    cin>>x;
			    l.setdate(i,x);
			}
			else
				cout<<"date erro"<<endl;
			show();
		}break;
	case 11:
		{
			int i,x;
			cout<<"��������Ҫȡ��Ԫ�ص�λ�ã�";
			cin>>i;
			if(l.getdate(i,x))
				cout<<"��Ԫ�ص�ֵ�ǣ�"<<x<<endl;
			show();
		}break;
	case 12:
		{
			l.makeempty();
			show();
		}break;
	default:cout<<"������������������������룺"<<endl;
	};
	}while(b!=0);
	return 0;
}
