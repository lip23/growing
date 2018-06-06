#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num;
	int dac(string&);
	while(cin>>num,num!=-1)
	{
		
		int start[101];
		int end[101];
		memset(start,-1,sizeof(start));
		memset(end,-1,sizeof(end));
		int count=0;
		int totaltime=0;
		while(1)
		{
			char op;
			string time;
			cin>>op>>time;
			if(num==0)
				break;
			if(op=='S')
			{
				if(start[num]!=-1&&end[num]!=-1)
				{
					count++;
					totaltime+=end[num]-start[num];
				}
				start[num]=dac(time);
				end[num]=-1;
			}
			else if(op=='E')
			{
				if(start[num]!=-1&&end[num]!=-1)
				{
					count++;
					totaltime+=end[num]-start[num];
					start[num]=-1;
				}
				end[num]=dac(time);
			}
			cin>>num;
			if(num==-1)
				break;
		}
		for(int i=1;i<101;i++)
			if(start[i]!=-1&&end[i]!=-1)
			{
				count++;
				totaltime=totaltime+end[i]-start[i];
			}
		cout<<count<<' ';
		if(count)
		{
			int t=totaltime/count;
			if(t*count!=totaltime)
				t++;
			cout<<t<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}

int dac(string& s)
{
	int minute=((s[0]-48)*10+s[1]-48)*60+(s[3]-48)*10+s[4]-48;
	return minute;
}
