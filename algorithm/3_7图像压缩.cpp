#include <iostream>
using namespace std;

int *data, *s, *b, *l;
void compress(int);
int lengths(int);
void show(int *a,int n);
void trackback(int &,int);
void output(int);

int main()
{
	char p;
	do{
		cout<<"please enter the number of the picture element sequence :";
		int n;
		cin>>n;
		data=new int[n+1];
		s=new int[n+1];
		b=new int[n+1];
		l=new int[n+1];
		cout<<"please enter the picelement sequence :\n";
		for(int i=1;i<=n;++i)cin>>data[i];
		compress(n);
		show(l,n);
		show(b,n);
		show(s,n);
		output(n);
		delete []data;
		delete []s;
		delete []b;
		delete []l; 
		cout<<"do you want to enter  a new picture element sequence :y=='yes'";
		cin>>p;
	}while(p=='y');
	return 0;
} 

void compress(int n)
{
	s[0]=0;
	for(int i=1;i<=n;++i){
		b[i]=lengths(data[i]);
		s[i]=s[i-1]+b[i];
		l[i]=1;
		int bmax=b[i];
		for(int k=2;k<=i&&k<=256;++k){
			if(bmax<b[i-k+1])bmax=b[i-k+1];
			int temp=s[i-k]+k*bmax;
			if(s[i]>temp){
				s[i]=temp;
				l[i]=k;
				b[i]=bmax;
			}
		}
		s[i]+=11;		
	}
}

int lengths(int d)
{
	int l=1;
	while(d/2){
		d/=2;
		++l;
	}
	return l;
}

void show(int *a,int n)
{
	for(int i=1;i<=n;++i)cout<<a[i]<<' ';
	cout<<endl;
}

void trackback(int &i,int n)
{
	if(n==0)return;
	trackback(i,n-l[n]);
	l[i++]=l[n];		
}

void output(int n)
{
	cout<<"the optimal value is :"<<s[n]<<endl;
	int m=0;
	trackback(m,n);
	cout<<"Decompose into "<<m<<" segments "<<endl;
	int pos=0;
	for(int j=0;j<m;++j){
		pos+=l[j];
		cout<<l[j]<<' '<<b[pos]<<endl;
	}
}
