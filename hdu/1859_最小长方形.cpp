#include <iostream>
using namespace std;
int main()
{
    int x,y;
    while(cin>>x>>y,x!=0||y!=0)
    {
        int xld=x,yld=y;
        int xru=x,yru=y;
        while(cin>>x>>y,x!=0||y!=0)
        {
            xld=(xld<x?xld:x);
            yld=(yld<y?yld:y);
            xru=(xru>x?xru:x);
            yru=(yru>y?yru:y);
        }
        cout<<xld<<' '<<yld<<' '<<xru<<' '<<yru<<endl;    
    }
    return 0;
}