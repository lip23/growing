#include <iostream>
using namespace std;
int main()
{
    int m,k;
    while(cin>>m>>k,m||k){
        int days=m;
        while(m>=k){
            days+=m/k;
            m=m%k+m/k;
        }
        cout<<days<<endl;
    }
    return 0;
}