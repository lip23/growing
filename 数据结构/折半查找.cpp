#include <iostream.h>
#include <malloc.h>
typedef struct
{
	int* elem;
	int size;
}list;


void initlist(list &l,int n)//��ʼ����СΪn��˳���
{
	l.elem=(int*)malloc(n*(sizeof(int)));
	if(!l.elem)
		cout<<"˳����ʼ��ʧ��"<<endl;
	cout<<"��ʼ���ɹ�"<<endl;
	cout<<"����������ҵ�Ԫ��"<<endl;
	for(int i=1;i<=n;i++)
		cin>>l.elem[i];
	cout<<"�����ҵ�Ԫ����"<<endl;
	for(int m=1;m<=n;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
	l.size=n;
	cout<<"��ʼ���ɹ���"<<endl;
}



void putoutlist(list l)
{
	int n=l.size;
	for(int m=1;m<=n;m++)
		cout<<l.elem[m]<<"  ";
	cout<<endl;
}




void paixu(list &l)//�����ݷ�������Ԫ������
{
	int m;
	for(int n=l.size;n>1;n--)
		for(int i=1;i<n;i++)
		{
			if(l.elem[i]>l.elem[i+1])
			{
				m=l.elem[i+1];
				l.elem[i+1]=l.elem[i];
				l.elem[i]=m;
			}
		}
}




void midsearch(list l,int e)//��l�в��ҹؼ���Ϊe��Ԫ��
{
	int low=1;
	int high=l.size;
	int mid=(low+high)/2;
	while(low<=high)
	{
		if(e<l.elem[mid])
		{
			high=mid-1;
			mid=(low+high)/2;
		}
		else if(e>l.elem[mid])
		{
			low=mid+1;
			mid=(low+high)/2;
		}
		else
		{
			cout<<"Ҫ���ҵĹؼ��ֵ�λ��i=  "<<mid<<endl;
			break;
		}
	}
	if(low>high)
		cout<<"��Ҫ���ҵĹؼ��ֲ������˳�����!"<<endl;
}





void main()
{
	char a;
	int n;
	list l;
	cout<<"�����������Ԫ�صĸ���n=  ";
	cin>>n;
	cout<<endl;
	initlist(l,n);
	cout<<"������������"<<endl;
	paixu(l);
	putoutlist(l);
	cout<<"��������Ҫ���ҵĹؼ���e=  ";
	cin>>n;
	cout<<endl;
	midsearch(l,n);
	cout<<"���Ƿ񻹼�������  y�����ǣ�n�����"<<endl;
	cin>>a;
	while(a=='y')
		{
			cout<<"��������Ҫ���ҵĹؼ���e=  ";
			cin>>n;
			cout<<endl;
			midsearch(l,n);
			cout<<"�Ƿ����"<<endl;
			cin>>a;
		}
	cout<<"������ֹ";
}
