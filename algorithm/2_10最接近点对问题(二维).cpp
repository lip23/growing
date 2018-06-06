#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

struct floaty
{
	int pos;
	float x; 
	float y;
	bool operator<(const floaty &a)const{return y<a.y;}
	void operator=(const floaty &a){x=a.x;y=a.y;pos=a.pos;}
};

struct floatx
{
	float x;
	float y;
	bool operator<(const floatx &a)const{return x<a.x;}  //注意两个const
	void operator=(const floaty &a){x=a.x;y=a.y;};
};
//bool operator<(const floatx &a,const floatx &b)//一定要加const，因为在sort中的变量都是常量，若不加const则函数不能调用（若形参
//{                                              // 为const则实参既可以是const也可是非const，若实参为非const则实参只能是非const） 
	//return a.x<b.x;
//}

void show(floatx *,int);
void show(floaty *,int);
void show(floaty *,int,int);
bool cpair2(floatx *,int,floatx &,floatx &,float &);
float distances(floatx &,floatx &);
float distances(floaty &,floaty &);
void closet(floatx *,floaty *,floaty *,int l,int r,floatx &,floatx &,float &);
void merge(floaty *,floaty *,int,int);
ostream & operator<<(ostream &out,floatx & a)
{
	out<<'('<<a.x<<','<<a.y<<')';
	return out;
}

int main()
{
	char p;
	ifstream cin("2_10.txt");
	do{
		cout<<"please enter the number of the points :\n";
		int n;
		cin>>n;
		N=n;
		floatx *X=new floatx[n];
		for(int i=0;i<n;++i){
			float tempx,tempy;
			cout<<"please enter the point x and y :\n";
			cin>>tempx>>tempy;
			X[i].x=tempx;
			X[i].y=tempy;
		}
		sort(X,X+n);
		//show(X,n);
		floatx a,b;
		float d;
		a.x=a.y=b.x=b.y=100;
		d=100;
		if(cpair2(X,n,a,b,d)){
			cout<<"the point is :\n"<<a<<' '<<b<<"\ndistance is: "<<d<<endl;
		}
		else cout<<"data is wrong.\n";
		delete []X;
		cout<<"do you want to enput some new points? y=='yes' :\n";
		cin>>p;
	}while(p=='y');
	cin.close();
}

void show(floatx * X,int n)
{
	for(int i=0;i<n;++i)
		cout<<'('<<X[i].x<<','<<X[i].y<<')'<<"  ";
	cout<<endl;
}

void show(floaty * X,int n)
{
	for(int i=0;i<n;++i)
		cout<<'('<<X[i].x<<','<<X[i].y<<')'<<X[i].pos<<"  ";
	cout<<endl;
}

void show(floaty * X,int l,int r)
{
	for(int i=l;i<r;++i)
		cout<<'('<<X[i].x<<','<<X[i].y<<')'<<X[i].pos<<"  ";
	cout<<endl;
}

bool cpair2(floatx * X,int n,floatx &a,floatx &b,float &d)
{
	if(n<2)return false;
	floaty *Y=new floaty[n];
	floaty *Z=new floaty[n];
	for(int i=0;i<n;++i){
		Y[i].x=X[i].x;
		Y[i].y=X[i].y;
		Y[i].pos=i;
	}
	sort(Y,Y+n);
	memcpy(Z,Y,n*sizeof(floaty));
	//show(Y,n);
	//show(Z,n);
	closet(X,Y,Z,0,n,a,b,d);
	delete []Y;
	delete []Z;
	return true;
}

void closet(floatx *X,floaty *Y,floaty *Z,int l,int r,floatx &a,floatx& b,float& d)
{
	//cout<<"l="<<l<<"  r="<<r<<endl;
	if(r-l==2){
		a=X[l];
		b=X[l+1];
		d=distances(X[l],X[l+1]);
		return;
	}
	else if(r-l==3){
		float d1=distances(X[l],X[l+1]);
		float d2=distances(X[l],X[l+2]);
		float d3=distances(X[l+1],X[l+2]);
		if(d1<d2&&d1<d3){a=X[l];b=X[l+1];d=d1;return;}
		else if(d2<d3){a=X[l];b=X[l+2];d=d2;return;}
		a=X[l+1];
		b=X[l+2];
		d=d3;
		return;
	}
	int m=(l+r)/2;
	int i=l;
	int j=m;
	//cout<<"l="<<l<<"  r="<<r<<"  m="<<m<<endl;
	for(int k=l;k<r;++k)
		if(Y[k].pos<m)Z[i++]=Y[k];
		else Z[j++]=Y[k];
	//cout<<"resolve :\n";
	//show(Z,l,r);
	floatx a1,a2,b1,b2;
	float d1,d2;
	closet(X,Z,Y,l,m,a1,b1,d1);
	//cout<<"a1="<<a1<<"  b1="<<b1<<"  d1="<<d1<<endl;
	closet(X,Z,Y,m,r,a2,b2,d2);
	//cout<<"a2="<<a2<<"  b2="<<b2<<"  d2="<<d2<<endl;
	if(d1<d2){a=a1;b=b1;d=d1;}
	else {a=a2;b=b2;d=d2;}
	//cout<<"a="<<a<<"  b="<<b<<"  d="<<d<<endl;
	//cout<<"l="<<l<<"  r="<<r<<"  m="<<m<<endl;
	//show(Y,N);
	//show(Z,N);
	//cout<<"l="<<l<<"  r="<<r<<"  m="<<m<<endl;
	merge(Y,Z,l,r);
	//cout<<"merge :\n";
	//show(Y,l,r);
	float mid=(X[m].x+X[m-1].x)/2;
	int k=l;
	for(i=l;i<r;++i)
		if(fabs(Y[i].x-mid)<d)Z[k++]=Y[i];
	//cout<<"zzzzzzzzzzzz: \n";
	//show(Z,l,k);
	for(i=l;i<k;++i)
		for(j=i+1;j<k;++j){
			if(Y[j].y-Y[i].y>d)break;
			float td=distances(Y[j],Y[i]);
			if(td<d){d=td;a=Y[i];b=Y[j];
				//cout<<"change :\n";
				//cout<<"a="<<a<<"  b="<<b<<"  d="<<d<<endl;
			}
		}
			
}

void merge(floaty *Y,floaty *Z,int l,int r)
{
	int m=(l+r)/2;
	int i=l;
	int j=m;
	int k=l;
	while(i<m&&j<r){
		if(Z[i]<Z[j])Y[k++]=Z[i++];
		else Y[k++]=Z[j++];
	}
	for(i;i<m;++i)Y[k++]=Z[i];//错误：Y[k++]=Z[i++] 在for循环中已经有i+1了，后边i++就会重复 
	for(j;j<r;++j)Y[k++]=Z[j];//错误：Y[k++]=Z[j++]
		
}

float distances(floatx& a,floatx& b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

float distances(floaty& a,floaty& b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
