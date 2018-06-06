#include <iostream>
#include <string>
using namespace std;

int **table;
int **subseq;
void LCSlength(string &s1,string &s2);
void show(int **,int,int);
void LCS(string &,int,int);

int main()
{
	char p;
	do{
		cout<<"please enter the two sequceces :\n";
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.size();
		int l2=s2.size();
		table=new int *[l1+1];
		subseq=new int *[l1+1];
		for(int i=0;i<=l1;++i){
			table[i]=new int[l2+1];
			subseq[i]=new int[l2+1];
		}
		LCSlength(s1,s2);
		//show(table,l1,l2);
		/*cout<<"::::::::::::::::::::::::::::::"<<endl;
		for(int i=1;i<=l1;++i){
			for(int j=1;j<=l2;++j)
				cout<<subseq[i][j]<<"  ";
			cout<<endl;
		}*/
		cout<<"the longest common subsequence is :";
		cout<<table[l1][l2]<<endl;
		LCS(s1,l1,l2);
		cout<<endl;
		for(int i=0;i<=l1;++i){
			delete []table[i];
			delete []subseq[i];
		}
		delete []table;
		delete []subseq;
		cout<<"do you want to create a new data ? y=='yes\n";
		cin>>p;
	}while(p=='y');
	return 0;
} 

void LCSlength(string &s1,string &s2)
{
	for(int i=0;i<=s1.size();++i)table[i][0]=0;
	for(int i=0;i<=s2.size();++i)table[0][i]=0;
	for(int i=0;i<s1.size();++i)
		for(int j=0;j<s2.size();++j){
			if(s1[i]==s2[j]){
				table[i+1][j+1]=table[i][j]+1;
				subseq[i+1][j+1]=2;
			}
			else if(table[i+1][j]>table[i][j+1]){
				table[i+1][j+1]=table[i+1][j];
				subseq[i+1][j+1]=1;
			}
			else {
				table[i+1][j+1]=table[i][j+1];
				subseq[i+1][j+1]=3;
			}
		}
}

void LCS(string &s1,int l1,int l2)
{
	if(l1==0||l2==0)return;
	if(subseq[l1][l2]==2){
		LCS(s1,l1-1,l2-1);
		cout<<s1[l1-1];
	}
	else if(table[l1-1][l2]>table[l1][l2-1])LCS(s1,l1-1,l2);
	else LCS(s1,l1,l2-1);
}

void show(int **t,int l1,int l2)
{
	for(int i=0;i<=l1;++i){
		for(int j=0;j<=l2;++j)
			cout<<t[i][j]<<"  ";
		cout<<endl;
	}
}
