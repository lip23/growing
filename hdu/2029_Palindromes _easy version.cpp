#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        string temp;
        cin>>temp;
        int l=temp.size();
        int m=l/2,k=l-1,i=0;
        for(i=0;i<m;i++)
            if(temp[i]!=temp[k-i]){
                cout<<"no"<<endl;
                break;
            }
        if(i==m)
            cout<<"yes"<<endl;
    }
    return 0;
}