#include <iostream>
using namespace std;
int main()
{
	int lin,col,i,j;
	cin>>lin>>col; 			//������������lin������col
	int **a;  
	a = new int*[lin];  		//lin����������int* ָ��
	for(i=0;i<lin;i++)
	    a[i]=new int[col];  	//ÿ����col����������int��
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
