#include <iostream>
using namespace std;

struct qnode
{
	int date;
	qnode * next;
};

int main()
{
	void creat(qnode *);
	qnode * head;
	creat(head);
	//void print();
	//void del();
	//void insert();
	return 0;
}

void creat(qnode *head)
{
	int n;
	cout<<"请输入您要建立的链表的大小n=";
	cin>>n;
	cout<<endl;
	qnode *p;
	qnode *q;
	p=new qnode;
	p->next=head;
	for(int i=0;i<n;i++)
	{
		q=new qnode;
		cin>>q->date;
		q->next=p->next;
		p->next=q;
	}
}
