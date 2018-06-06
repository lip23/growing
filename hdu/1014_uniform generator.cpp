#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int step,mod;
    while(cin>>step>>mod)
    {
        int c=0,temp=0;
        do
        {
            c++;
            temp=(temp+step)%mod;
        }while(temp!=0);
        cout<<setiosflags(ios::right);
        cout<<setw(10)<<step<<setw(10)<<mod<<setw(4)<<' ';
        cout<<setiosflags(ios::left);
        if(c==mod)
            cout<<"Good Choice"<<endl;
        else
            cout<<"Bad Choice"<<endl;
		cout<<endl;
    }
    return 0;
}