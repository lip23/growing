#include <iostream>
#include <iomanip>
using namespace std;
enum ball
{
	red,yellow,blue,white,black
};


ball b1,b2,b3;

int main()
{
	cout<<setiosflags(ios::left);
	int total=0;
	int i,j,k;
	for(i=red;i<=black;i++)
		for(j=red;j<=black;j++)
			for(k=red;k<=black;k++)
				if(k!=i&&k!=j&&i!=j)
				{
					total++;
					cout<<setw(5)<<total;
					switch(i)
					{
					case red:cout<<setw(8)<<"red";break;
					case yellow:cout<<setw(8)<<"yellow";break;
					case blue:cout<<setw(8)<<"blue";break;
					case white:cout<<setw(8)<<"white";break;
					case black:cout<<setw(8)<<"black";break;
					}
					switch(j)
					{
					case red:cout<<setw(8)<<"red";break;
					case yellow:cout<<setw(8)<<"yellow";break;
					case blue:cout<<setw(8)<<"blue";break;
					case white:cout<<setw(8)<<"white";break;
					case black:cout<<setw(8)<<"black";break;
					}
					switch(k)
					{
					case red:cout<<setw(8)<<"red";break;
					case yellow:cout<<setw(8)<<"yellow";break;
					case blue:cout<<setw(8)<<"blue";break;
					case white:cout<<setw(8)<<"white";break;
					case black:cout<<setw(8)<<"black";break;
					}
					cout<<endl;
				}
	return 0;
}
	
