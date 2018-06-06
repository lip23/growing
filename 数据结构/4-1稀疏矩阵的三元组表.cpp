#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
//using namespace std;

const int defaultsize=100;

struct trituple
{
	int row;
	int col;
	int value;
	void operator = (trituple & x)
	{
		row=x.row;
		col=x.col;
		value=x.value;
	}
};

class sparsematrix
{
public:
	sparsematrix(int=defaultsize);
	sparsematrix(sparsematrix &);
	~sparsematrix();
	sparsematrix  operator = (sparsematrix & x);
	sparsematrix transpose();
	sparsematrix add(sparsematrix & a);
	sparsematrix multiply(sparsematrix & b);
	friend ostream & operator <<(ostream & ,sparsematrix &);
	friend istream & operator >>(istream & ,sparsematrix &);
	void sort();
private:
	int rows;
	int cols;
	int terms;
	trituple * smarray;
	int maxterms;
};

int main()
{
	ifstream infile("4a.txt");
	sparsematrix s1,s2;
	infile>>s1;
	s1.sort();
	cout<<s1;
	infile>>s2;
	s2.sort();
	cout<<s2;
	sparsematrix s3=s1.multiply(s2);
	cout<<s3;
	infile.close();
	/*sparsematrix a,b;
	cin>>a;
	a.sort();
	cout<<a;
	cin>>b;
	b.sort();
	cout<<b;
	sparsematrix c=a.add(b);
	c.sort();
	cout<<c;
	sparsematrix s;
	cin>>s;
	s.sort();
	sparsematrix st=s.transpose();
	cout<<s;
	cout<<st;*/
	return 0;
}

sparsematrix::sparsematrix(int maxsz)
{
	maxterms=maxsz;
	smarray=new trituple[maxsz];
	if(smarray==NULL)
		cout<<"三元组初始化失败"<<endl;
	else
		cout<<"三元组初始化成功"<<endl;
	rows=terms=cols=0;
}

sparsematrix::sparsematrix(sparsematrix & x)
{
	rows=x.rows;
	cols=x.cols;
	terms=x.terms;
	maxterms=x.maxterms;
	smarray=new trituple[maxterms];	
	
	for(int i=0;i<terms;i++)
		smarray[i]=x.smarray[i];
}


sparsematrix::~sparsematrix()
{
	delete [] smarray;
	cout<<"析构成功"<<endl;
}

ostream & operator << (ostream & output,sparsematrix & s)
{
	output<<setw(3)<<' '<<setw(6)<<"row"<<setw(6)<<"col"<<setw(7)<<"value"<<endl;
	for(int i=0;i<s.terms;i++)
		output<<'['<<i<<']'<<setw(5)<<s.smarray[i].row<<setw(6)<<s.smarray[i].col<<setw(6)<<s.smarray[i].value<<endl;
	output<<"( rows="<<s.rows<<"  cols="<<s.cols<<"  terms="<<s.terms<<" )"<<endl;
	return output;
}
	
istream & operator >>(istream & input ,sparsematrix & x)
{
	//cout<<"请输入稀疏矩阵的 rows: ";
	input>>x.rows;
	//cout<<"请输入稀疏矩阵的 cols: ";
	input>>x.cols;
	//cout<<"请输入稀疏矩阵的 terms: ";
	input>>x.terms;
	for(int i=0;i<x.terms;i++)
	{
		//cout<<"请输入个元组的 row , col , value :";
		input>>x.smarray[i].row>>x.smarray[i].col>>x.smarray[i].value;
	}
	return input;
}

void sparsematrix::sort()
{
	int t;
	trituple temp;
	for(int i=0;i<terms;i++)
	{
		t=i;
		for(int j=i+1;j<terms;j++)
			if(smarray[j].row<smarray[t].row)
				t=j;
			else if(smarray[j].row==smarray[t].row)
				if(smarray[j].col<smarray[t].col)
					t=j;
		temp=smarray[i];
		smarray[i]=smarray[t];
		smarray[t]=temp;
	}
}

sparsematrix sparsematrix::transpose()
{
	sparsematrix t;
	t.terms=terms;
	t.rows=cols;
	t.cols=rows;
	for(int i=0;i<terms;i++)
	{
		t.smarray[i].row=smarray[i].col;
		t.smarray[i].col=smarray[i].row;
		t.smarray[i].value=smarray[i].value;
	}
	t.sort();
	return t;
}

sparsematrix sparsematrix::add(sparsematrix & a)
{
	int i=0,j=0;
	sparsematrix b;
	b.rows=rows;
	b.cols=cols;
	while(i<terms&&j<a.terms)
	{
		if(smarray[i].row<a.smarray[j].row)
		{
			b.smarray[b.terms]=smarray[i];
			i++;
		}
		else if(smarray[i].row>a.smarray[j].row)
		{
			b.smarray[b.terms]=a.smarray[j];
			j++;
		}
		else
		{
			if(smarray[i].col==a.smarray[j].col)
			{
				b.smarray[b.terms]=smarray[i];
				b.smarray[b.terms].value=smarray[i].value+a.smarray[j].value;
				i++;
				j++;
			}
			else if(smarray[i].col<a.smarray[j].col)
			{
				b.smarray[b.terms]=smarray[i];
				i++;
			}
		   else
		   {
			   b.smarray[b.terms]=a.smarray[j];
			   j++;
		   }
		}
		b.terms++;
	}
	while(i<terms)
	{
		b.smarray[b.terms]=smarray[i];
		b.terms++;
		i++;
	}
	while(j<a.terms)
	{
		b.smarray[b.terms]=a.smarray[j];
		j++;
		b.terms++;
	}
	return b;
}

sparsematrix sparsematrix::multiply(sparsematrix & b)
{
	int i,j;
	sparsematrix a;
	a.rows=rows;
	a.cols=b.cols;
	for(i=0;i<terms;i++)
		for(j=0;j<b.terms;j++)
			if(smarray[i].col==b.smarray[j].row)
			{
				a.smarray[a.terms].row=smarray[i].row;
				a.smarray[a.terms].col=b.smarray[j].col;
				a.smarray[a.terms].value=smarray[i].value*b.smarray[j].value;
				a.terms++;
			}
	j=0;
	a.sort();
	while(j<a.terms-1)
	{
		if(a.smarray[j].row==a.smarray[j+1].row&&a.smarray[j].col==a.smarray[j+1].col)
		{
			a.smarray[j].value=a.smarray[j].value+a.smarray[j+1].value;
			for(int k=j+1;k<a.terms-1;k++)
				a.smarray[k]=a.smarray[k+1];
			a.terms--;
		}
		else
			j++;
	}
	return a;
}



