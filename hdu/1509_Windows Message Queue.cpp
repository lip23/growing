#include <iostream>
#include <string>
using namespace std;

struct message
{
	string name;
	int par;
	int pri;
	message* link;
	//message():link(NULL){}
	message(){};
	message(string n,int pa,int pr):par(pa),pri(pr){name=n;}
};

class queue
{
public:
	queue();
	~queue();
	void enqueue(message& m);
	void dequeue();
	bool isempty();
	void show();
private:
	message* front;
	//message* rear;
};

int main()
{
	char command[4];
	queue q;
	while(cin>>command)
	{
		if(strcmp(command,"GET")==0)
		{
			if(q.isempty())
				cout<<"EMPTY QUEUE!"<<endl;
			else
				q.dequeue();
		}
		else if(strcmp(command,"PUT")==0)
		{
			message temp;
			cin>>temp.name>>temp.par>>temp.pri;
			q.enqueue(temp);
			//q.show();
		}
	}
	return 0;
}


queue::queue()
{
	front=new message;
	front->link=NULL;
	//rear=front->link;

}

queue::~queue()
{
	while(front)
	{
		message* del=front;
		front=front->link;
		delete del;
	}
}

void queue::enqueue(message& m)
{
	message* cur=front;
	while(cur->link&&m.pri>=cur->link->pri)
		cur=cur->link;
	message* nme=new message(m.name,m.par,m.pri);
	nme->link=cur->link;
	cur->link=nme;
	//show();
}

void queue::dequeue()
{
	message* del=front->link;
	front->link=del->link;
	cout<<del->name<<' '<<del->par<<endl;
	delete del;
}


bool queue::isempty()
{
	//if(front->link==NULL)
		//return true;
	//return false;
	if(front->link)
		return false;
	return true;
}

void queue::show()
{
	message* cur=front->link;
	cout<<"show:";
	while(cur)
	{
		//cout<<"kkkkk"<<endl;
		cout<<cur->name<<' '<<cur->par;
		cur=cur->link;
	}
	cout<<endl;
}




