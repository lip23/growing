#include <iostream>
using namespace std;

template <class T,int n>//�ڽ�������ʱҪ��n���г�ʼ����n�൱��һ������

class tmplt
{
public:
	void detain();
	void reverseout();
private:
	T arr[n];
};

template <class T,int n>

void tmplt<T,n>::detain()
{
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

template <class T,int n>

void tmplt<T,n>::reverseout()
{
	for(int i=n-1;i>=0;i--)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	tmplt <int,5> t1;//�ڽ�������ʱҪ��n���г�ʼ��
	t1.detain();
	t1.reverseout();
	tmplt <char,5> t2;
	t2.detain();
	t2.reverseout();
	return 0;
}

