#include <iostream>
using namespace std;

int main()
{
	int n;////////////////////////////////////scanf("%d,%d,%d",&a,&b,&c);
	while(scanf("%d",&n),n!=0)
	{
		int start=-1,end=-1,count=-1;
		int* data=new int[n];
		for(int rear=0;rear<n;rear++)
			scanf("%d",&data[rear]);
			//cin>>data[rear];
		for(int front=0;data[front]<0&&front<n;front++);
		if(front==rear)
			cout<<0<<' '<<data[0]<<' '<<data[rear-1]<<endl;
		else
		{
			for(rear--;data[rear]<0;rear--);
			int temp=0;
			for(int i=front;i<=rear;i++)
			{
				temp+=data[i];	
				if(temp<0)
				{
					temp=0;
					front=i+1;
				}
				//if(start!=front)
					//start=front;
				if(temp>count)
				{
					count=temp;
					start=front;
					end=i;
				}
			
			}
			for(start;data[start]==0&&start!=end;start++);
			for(end;data[end]==0&&end!=start;end--);
			cout<<count<<' '<<data[start]<<' '<<data[end]<<endl;
		}
		delete []data;
	}
	return 0;
}

