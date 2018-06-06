#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        _int64 m;
        cin>>m;
        _int64 k=sqrt(1.0*m);
        while(k*(k+1)<2*m)k++;
        k-=1;
        int result=(m-k*(k+1)/2-1)%9+1;
        cout<<result<<endl;
    }
    return 0;
}