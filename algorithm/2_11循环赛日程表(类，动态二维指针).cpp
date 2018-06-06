#include <iostream>
#include <iomanip>
using namespace std;

int c=0;

class table{
public:
	table(int);
	~table();
	void show();
	int size;
	int **t;
};

void cyclematchtable(table &,int,int);

int main()
{
	char p;
	do{
		cout<<"please enter the number of people joined the match :";
		int k;
		cin>>k;
		table cmt(k);
		cyclematchtable(cmt,0,k);
		cout<<"the cycle match table is :\n";
		cmt.show();
		cout<<"do you want to creat a new match table? y=='yes'\n";
		cin>>p;
	}while(p=='y');
	return 0;
} 

void cyclematchtable(table & cmt,int l,int r)
{
	//cout<<"original\n";
	//cout<<"l="<<l<<"   r="<<r<<endl;
	//++c;
	//if(c==20)exit(1);
	if(r-l==2){
		cmt.t[r-1][1]=cmt.t[l][0]=l+1;
		cmt.t[r-1][0]=cmt.t[l][1]=r;
		//cout<<"222222222222\n";
		//cmt.show();
		return;
		//cmt.t[r][0]=r+1;
		//cmt.t[r][1]=l+1;
	}
	int m=(l+r)/2;
	int s=(r-l)/2;
	//cout<<"original\n";
	//cmt.show();
	cyclematchtable(cmt,l,m);
	cyclematchtable(cmt,m,r);
	for(int i=0;i<s;++i)
		for(int j=0;j<s;++j){//重点弄清楚在对角复制时行列的初始值，特别注意列的初始值就是当前问题的规模 
			cmt.t[l+i][s+j]=cmt.t[s+l+i][j];
			cmt.t[m+i][s+j]=cmt.t[m+i-s][j];
		}	
	//cout<<"meger:\n";
	//cout<<"l="<<l<<"   r="<<r<<endl;
	//cmt.show();
}

table::table(int k)
{
	size=k;
	t=new int *[k];
	for(int i=0;i<k;++i)
		t[i]=new int[k];
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)
			t[i][j]=0;
}

table::~table()
{
	for(int i=0;i<size;++i)
		delete []t[i];
	delete []t; 
} 

void table::show()
{
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)
			cout<<setw(3)<<t[i][j];
		cout<<endl;	
	}
}
