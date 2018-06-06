#include <iostream>
#include <string>
using namespace std;

struct site
{
	char name[21];
	double rp;
	site* link;
	site(char n[21],double r):rp(r){strcpy(name,n);}
	site(){};
};

class train
{
public:
	train();
	~train();
	void getin(site s);
	void getout();
	void show();
	void Union(train&  t);
	site* getf();
private:
	site* front;
};

int main()
{
	int n,o;
	while(cin>>n>>o)
	{
	train* t=new train[n];
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		for(int j=0;j<m;j++)
		{
			site temp;
			cin>>temp.name>>temp.rp;
			t[i].getin(temp);
		}
	}
	char operat[3][7]={"GETON","JOIN","GETOUT"};
	for(i=0;i<o;i++)
	{
		char tope[7];
		cin>>tope;
		if(strcmp(tope,operat[0])==0)
		{
			int k;
			cin>>k;
			site temp;
			cin>>temp.name>>temp.rp;
			t[k-1].getin(temp);
		}
		else if(strcmp(tope,operat[1])==0)
		{
			int m1,m2;
			cin>>m1>>m2;
			t[m1-1].Union(t[m2-1]);
		}
		else if(strcmp(tope,operat[2])==0)
		{
			int k;
			cin>>k;
			t[k-1].getout();
		}
	}
	delete []t;
	}
	return 0;
}

train::train()
{
	front=new site;
	front->link=NULL;
}

train::~train()
{
	site* del=front;
	while(del)
	{
		site* temp=del->link;
		delete del;
		del=temp;
	}	
}

void train::getin(site s)
{
	site* newsite=new site(s.name,s.rp);
	newsite->link=front->link;
	front->link=newsite;
}

void train::getout()
{
	site* temp=front;
	site* cur=front->link;
	while(cur->link)
	{
		if(cur->link->rp<temp->link->rp)
			temp=cur;
		else if(cur->link->rp==temp->link->rp)
			if(strcmp(cur->link->name,temp->link->name)>0)
				temp=cur;
		cur=cur->link;
	}
	cout<<temp->link->name<<endl;
	cur=temp->link;
	temp->link=cur->link;
	delete cur;
}

void train::show()
{
	site* temp=front->link;
	while(temp)
	{
		cout<<temp->name<<' '<<temp->rp<<endl;
		temp=temp->link;
	}
}

void train::Union(train& t)
{
	site* temp=t.getf();
	site* cur=front;
	while(cur->link)
		cur=cur->link;
	cur->link=temp->link;
	temp->link=NULL;
}

site* train::getf()
{
	return front;
}


	





