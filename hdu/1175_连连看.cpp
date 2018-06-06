#include <iostream>
using namespace std;

struct node
{
	int pos1;
	int pos2;
	int count;
	int direct;
};

class stack
{
public:
	stack();
	~stack(){};
	void push(int,int,int,int);
	void pop(int&,int&,int&,int&);
	bool isempty();
private:
	int top;
	node data[2002];
};
	

int main()
{
	int m,n;
	while(cin>>n>>m,n+m!=0)
	{
		int** graph=new int* [n];
		for(int i=0;i<n;i++)
			graph[i]=new int[m];
		for(i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>graph[i][j];
		int op,s1,s2,e1,e2;
		cin>>op;
		for(int ii=0;ii<op;ii++)
		{
			cin>>s1>>s2>>e1>>e2;
			int value1=graph[s1-1][s2-1];
			int value2=graph[e1-1][e2-1];
			if(value1!=value2||value1==0||value2==0)
				cout<<"NO"<<endl;
			else
			{
				int cur1=s1-1,cur2=s2-1;
				graph[s1-1][s2-1]=0;
				graph[e1-1][e2-1]=0;
				stack s;
				int c=0;
				int direction=0;
				do
				{
					cout<<"direction="<<direction<<endl;
					cout<<"count="<<c<<endl;
					if(cur2+1<m&&graph[cur1][cur2+1]==0&&(direction==1||(direction!=1&&c<2)))
					{
						cout<<"11111111111"<<endl;
						s.push(cur1,cur2,c,direction);
						graph[cur1][cur2]=-1;
						cout<<"please input"<<endl;
						int temp;	
						cin>>temp;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						cur2++;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						//cout<<"cur2="<<cur2<<endl;
						if(direction!=0&&direction!=1)
							c++;
						direction=1;
					}
					else if(cur1+1<n&&graph[cur1+1][cur2]==0&&(direction==2||(direction!=2&&c<2)))
					{
						cout<<"22222222222222"<<endl;
						s.push(cur1,cur2,c,direction);
						graph[cur1][cur2]=-1;
						cout<<"please input"<<endl;
						int temp;	
						cin>>temp;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						cur1++;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						//cout<<"cur1="<<cur1<<endl;
						if(direction!=0&&direction!=2)
								c++;
						direction=2;
					}
					else if(cur2-1>=0&&graph[cur1][cur2-1]==0&&(direction==3||(direction!=3&&c<2)))
					{
						cout<<"3333333333333333333"<<endl;
						s.push(cur1,cur2,c,direction);
						graph[cur1][cur2]=-1;
						cout<<"please input"<<endl;
						int temp;	
						cin>>temp;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						cur2--;	
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						//cout<<"cur2="<<cur2<<endl;
						if(direction!=0&&direction!=3)
								c++;
						direction=3;
					}
					else if(cur1-1>=0&&graph[cur1-1][cur2]==0&&(direction==4||(direction!=4&&c<2)))
					{
						cout<<"444444444444444444"<<endl;
						s.push(cur1,cur2,c,direction);
						graph[cur1][cur2]=-1;
						cout<<"please input"<<endl;
						int temp;	
						cin>>temp;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						cur1--;	
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						//cout<<"cur1="<<cur1<<endl;
						if(direction!=0&&direction!=4)
								c++;
						direction=4;
					}
					else
					{
						cout<<"5555555555555555555555"<<endl;
						if(s.isempty())
							break;
						int temp;
						cin>>temp;
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						graph[cur1][cur2]=-1;
						s.pop(cur1,cur2,c,direction);
						cout<<"cur1="<<cur1<<"   cur2="<<cur2<<endl;
						cout<<"direc="<<direction<<endl;
						cout<<"count="<<c<<endl;
					}
				}while(cur1!=e1-1||cur2!=e2-1);
				if(s.isempty())
					cout<<"NO"<<endl;
				else
					cout<<"YES"<<endl;
				for(i=0;i<n;i++)
					for(int k=0;k<m;k++)
						if(graph[i][k]==-1)
							graph[i][k]=0;
						//cout<<graph[i][k]<<' ';
					//cout<<endl;
				graph[s1-1][s2-1]=value1;
				graph[e1-1][e2-1]=value2;
			}
		}
		for(i=0;i<n;i++)
			delete []graph[i];
		delete []graph;
	}
	return 0;
}

stack::stack()
{
	top=0;
}

void stack::push(int c1,int c2,int c,int d)
{
	data[top].pos1=c1;
	data[top].pos2=c2;
	data[top].count=c;
	data[top].direct=d;
	top++;
}

void stack::pop(int& c1,int& c2,int& c,int& d)
{
	top--;
	c1=data[top].pos1;
	c2=data[top].pos2;
	c=data[top].count;
	d=data[top].direct;
}

bool stack::isempty()
{
	return top==0?true:false;
}

			
