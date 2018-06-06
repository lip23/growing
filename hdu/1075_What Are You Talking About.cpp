#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

struct word
{
	char data[11];
};


int main()
{
	string line;
	vector<word> v1;
	while(getline(cin,line))
	{
		if(line=="END")
			break;
		for(int i=0;line[i];i++)
		{
			int k=0;
			word temp;
			while(islower(line[i])&&line[i])
			{
				 temp.data[k]=line[i];
				 k++;
				 i++;
			}
			temp.data[k]='\0';
			v1.push_back(temp);
		}
	}
	int size=v1.size();
	getline(cin,line);
	while(getline(cin,line))
	{
		if(line=="END")
			break;
		for(int i=0;line[i];i++)
		{
			if(islower(line[i]))
			{
				int k=0;
				word temp;
				while(islower(line[i])&&line[i])
				{
					temp.data[k]=line[i];
					k++;
					i++;
				}
				temp.data[k]='\0';
				for(int j=1;j<size;j+=2)
				{
					if(strcmp(temp.data,v1[j].data)==0)
					{
						cout<<v1[j-1].data;
						break;
					}
					else if(j==size-1)
						cout<<temp.data;
				}
				i--;
			}
			else
				cout<<line[i];
		}
		cout<<endl;
		
	}
	return 0;
}
