#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
 int n;
 string a,b;
 while(cin>>n&&n)
 {
  set<string> loser,total;
  while(n--)
  {
   cin>>a>>b;
   total.insert(a);
   total.insert(b);
   loser.insert(b);
  }
  if(total.size()==loser.size()+1)
   cout<<"Yes"<<endl;
  else
   cout<<"No"<<endl;
 }
 return 0;
}
