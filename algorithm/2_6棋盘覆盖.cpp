#include <iostream>
#include <iomanip>
using namespace std;

int tile;
void coverboard(int **,int,int,int,int,int);
void Printf(int **,int);

int main()
{
	char p;
	do{
		void Printf(int **,int);
		int size,x,y;
		cout<<"please enter the size of the chessboard :";
		cin>>size;
		int **chessboard=new int *[size];
		for(int i=0;i<size;++i)
			chessboard[i]=new int[size];
		cout<<"please enter the special point's x and y :";
		cin>>x>>y;
		tile=0;
		chessboard[x][y]=tile;
		coverboard(chessboard,x,y,size-1,size-1,size);
		Printf(chessboard,size);
		for(int i=0;i<size;++i)
			delete []chessboard[i];
		delete []chessboard;
		cout<<"do you want to continue ? y='yes'\n";
		cin>>p;	
	}while(p=='y');
	return 0;
} 

void Printf(int **cb,int s)
{
	for(int i=0;i<s;++i){
		for(int j=0;j<s;++j)
			cout<<setw(5)<<cb[i][j];
		cout<<endl;
	}
}

void coverboard(int **cb,int x,int y,int rx,int ry,int s)
{
	if(s==1)return;
	int t=++tile;
	s/=2;
	if(x<=rx-s&&y<=ry-s)
		coverboard(cb,x,y,rx-s,ry-s,s);
	else{ 
		cb[rx-s][ry-s]=t;
		coverboard(cb,rx-s,ry-s,rx-s,ry-s,s); 
	} 
	if(x<=rx-s&&y>ry-s&&y<=ry)
		coverboard(cb,x,y,rx-s,ry,s);
	else{
		cb[rx-s][ry-s+1]=t;
		coverboard(cb,rx-s,ry-s+1,rx-s,ry,s);
	}	
	if(x<=rx&&x>rx-s&&y<=ry-s)
		coverboard(cb,x,y,rx,ry-s,s);
	else{
		cb[rx-s+1][ry-s]=t;
		coverboard(cb,rx-s+1,ry-s,rx,ry-s,s);
	} 
	if(x>rx-s&&x<=rx&&y>ry-s&&y<=ry)
		coverboard(cb,x,y,rx,ry,s);
	else{
		cb[rx-s+1][ry-s+1]=t;
		coverboard(cb,rx-s+1,ry-s+1,rx,ry,s); 
	}
}
