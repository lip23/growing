#include <iostream>
using namespace std;
int main()
{
	int lin,col,i,j;
	cin>>lin>>col; 			//任意输入行数lin及列数col
	int **a;  
	a = new int*[lin];  		//lin（行数）个int* 指针
	for(i=0;i<lin;i++)
	    a[i]=new int[col];  	//每行有col（列数）个int数
	for(i=0;i<lin;i++)
	    for(j=0;j<col;j++)
		{
			a[i][j]=i+j;
			cout<<a[i][j]<<" ";
		}
	cout<<endl;
	delete a;
	return 0;
}
