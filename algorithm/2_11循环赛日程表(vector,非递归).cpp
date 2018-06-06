#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void cyclematchtable(vector<vector<int> > &,int);
void show(vector<vector<int> > &,int);

int main()
{
	char p;
	do{
		cout<<"please enter the number of people joined tha match :";
		int k;
		cin>>k;
		vector<vector<int> > table(k,vector<int>(k,0));
		//show(table,k);
		//cout<<table[0].size()<<endl;
		//cout<<table.size()<<endl;
		cyclematchtable(table,k);
		cout<<"ok\n";
		cout<<"the cycle match table is:\n";
		show(table,k);
		table.clear();
		cout<<"do you want to creat a new match table? y=='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
} 

void cyclematchtable(vector<vector<int> > &table,int k)
{
	for(int i=0;i<k;++i)
		table[i][0]=i+1;
	for(int s=1;s<k;s*=2)
		for(int row=0;row<k;row+=2*s)
			for(int i=0;i<s;++i)
				for(int j=0;j<s;++j){
					table[row+i][s+j]=table[row+i+s][j];
					table[row+s+i][s+j]=table[row+i][j];
				}
}

void show(vector<vector<int> > &table,int k)
{
	for(int i=0;i<k;++i){
		for(int j=0;j<k;++j)
			cout<<setw(3)<<table[i][j];
		cout<<endl;	
	}
}
