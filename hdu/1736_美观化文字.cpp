#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	char ori[7]={',','.','!','"','<','>','?'};
	char cht[8][4]={"£¬","¡£","£¡","¡°","¡¶","¡·","£¿","¡±"};
	while(getline(cin,word))
	{
		int k=0;
		int times=0;
		while(word[k])
		{
			if(word[k]<0)
			{
				char temp[3];
				temp[0]=word[k];
				temp[1]=word[k+1];
				temp[2]='\0';
				cout<<temp;
				if(strcmp(temp,"¡°")==0||strcmp(temp,"¡±")==0)
					times++;
				k+=2;
			}
			else
			{
				bool found=false;
				for(int i=0;i<7;i++)
					if(word[k]==ori[i])
					{
						found=true;
						if(i==3)
							times++;
						if(i==3&&times%2==0)
						{
								cout<<cht[7];
								break;
						}
						if(i==4||i==5)
							if(word[k]!=word[k+1])
								cout<<word[k];
							else
							{
								cout<<cht[i];
								k++;
								break;
							}
						else
						{
							cout<<cht[i];
							break;
						}
					}
				if(!found)
					cout<<word[k];
				k++;
			}
		}
		cout<<endl;
	}
	return 0;
}
