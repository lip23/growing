#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct whitestate
{
	int start;
	int end;
	int length;
	bool map;
	whitestate(int s,int e,int l,bool m=true):start(s),end(e),length(l),map(m){}
};

struct blackstate
{
	int start;
	int end;
	blackstate(int s,int e):start(s),end(e){}
};

bool cmp1(whitestate w1,whitestate w2)
{
	if(w1.start!=w2.start)
		return w1.start<w2.start;
	else 
		return w1.end<w2.end;
}


int main()
{
	int n;
	while(cin>>n)
	{
		int a,b;
		char c;
		vector<whitestate> ws;
		vector<blackstate> bs;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			if(c=='w')
			{
				whitestate temp(a,b,b-a);
				ws.push_back(temp);
			}
			else if(c=='b')
			{
				blackstate temp(a,b);
				bs.push_back(temp);
			}
		}
		sort(ws.begin(),ws.end(),cmp1);
		for(int k=1;k<ws.size();k++)
			if(ws[k].start<=ws[k-1].start)
			{
				ws[k-1].map=false;
				ws[k].start=ws[k-1].start;
				ws[k].length=ws[k].end-ws[k].start;
			}
		for(k=0;k<bs.size();k++)
			for(int j=0;j<ws.size();j++)
				if(ws[j].map&&bs[k].start>=ws[j].star&&bs[k].start<=ws[j].end)
				{
					if(bs[k].start==ws[j].start)
					{
						ws[j].start++;
						ws[j].length--;
						if(ws[j].length==0)
							ws[j].map=false;
					}
					else if(bs[k].start==ws[j].end)
					{
						ws[j].end--;
						ws[j].length--;
						if(ws[j].length==0)
							ws[j].map=false;
					}
					else
					{


	}
	return 0;
}









