#include <iostream>
using namespace std;

struct qnode
{
	int number;
	int score;
    qnode *next;
};

int main()
{
	qnode q1,q2,q3;
	q1.number=3100;
	q2.number=3103;
	q3.number=3107;
	q1.score=87;
	q2.score=90;
	q3.score=98;
	qnode * h;
	h=&q1;
	q1.next=&q2;
	q2.next=&q3;
	q3.next=NULL;
	qnode *p;
	p=h;
	do
	{
		cout<<p->number<<" "<<p->score<<endl;
		p=p->next;
	}while(p);
	return 0;
}
	