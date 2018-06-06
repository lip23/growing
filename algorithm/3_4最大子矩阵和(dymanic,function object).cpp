#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

class maxmatrixsum
{
	public:
		maxmatrixsum(int=0,int=0);
		~maxmatrixsum();
		friend int maxsum1(vector<int> &v,int &bi,int &bj);
		void maxsum2();
		void show();
		void display();
	private:
		int ** matrix;
		int m,n;
		int bri,brj,bci,bcj,max;
};

int main()
{
	char p;
	do{
		cout<<"pelase enter the row and col of a random matrix :";
		int row,col;
		cin>>row>>col;
		maxmatrixsum maxsum(row,col);
		maxsum.show();
		maxsum.maxsum2();
		maxsum.display();
		cout<<"do you want to creat a new randow matrix ? y=='yes' :";
		cin>>p;
	}while(p=='y');
	return 0;
}

maxmatrixsum::maxmatrixsum(int a,int b)
{
	m=a;
	n=b;
	matrix=new int *[m];
	for(int i=0;i<m;++i){
		matrix[i]=new int[n];
		for(int j=0;j<n;++j)
			matrix[i][j]=rand()%100-50;
	}
}

maxmatrixsum::~maxmatrixsum()
{
	for(int i=0;i<m;++i)delete []matrix[i];
	delete []matrix;
}

void maxmatrixsum::show()
{
	cout<<"the random matix is :\n";
	cout<<setw(5)<<' ';
	for(int i=1;i<=n;++i)cout<<setw(5)<<i;
	cout<<endl;
	for(int i=0;i<m;++i){
		cout<<setw(5)<<i+1;
		for(int j=0;j<n;++j)
			cout<<setw(5)<<matrix[i][j];
		cout<<endl;
	}
}

void maxmatrixsum::maxsum2()
{
	//int bri,brj,bci,bcj,max;
	bri=brj=bci=bcj=max=0;
	for(int ri=0;ri<m;++ri)
		for(int rj=ri;rj<m;++rj){
			vector<int> temp(n);
			for(int i=0;i<n;++i)
				for(int j=ri;j<=rj;++j)
					temp[i]+=matrix[j][i];
			int tci=0;
			int tcj=0;
			int tsum=maxsum1(temp,tci,tcj);
			if(tsum>max){max=tsum;bci=tci;bcj=tcj;bri=ri+1;brj=rj+1;}	
		}
}

int maxsum1(vector<int> &v,int &bi,int &bj)
{
	int sum=0;
	int tsum=0;
	int ti=0;
	for(int i=0;i<v.size();++i){
		if(tsum>0)tsum+=v[i];
		else {tsum=v[i];ti=i;}
		if(tsum>sum){sum=tsum;bi=ti+1;bj=i+1;}
	}
	return sum;
}

void maxmatrixsum::display()
{
	cout<<"the best ri is :"<<bri<<endl;
	cout<<"the best rj is :"<<brj<<endl;
	cout<<"the best ci is :"<<bci<<endl;
	cout<<"the best cj is :"<<bcj<<endl;
	cout<<"the max sum is :"<<max<<endl;
}
