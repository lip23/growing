#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double data[100];
    char buf[100];
    int bcur=0,dcur=0;    
    double n;
    char temp;
    while(cin>>n,cin.get(temp),n!=0||temp!='\n')
    {
        data[dcur++]=n;
		//cout<<"data[0]="<<data[0]<<endl;
        do
        {
            cin>>temp>>n;
            if(temp=='+'||temp=='-')
            {
                buf[bcur++]=temp;
                data[dcur++]=n;
            }
            else if(temp=='*')
                data[dcur-1]*=n;
            else if(temp=='/')
                data[dcur-1]/=n;    
        }while(cin.get(temp),temp!='\n');
		//cout<<"dcur="<<dcur<<endl;
		//cout<<"bcur="<<bcur<<endl;
		//for(int i=0;i<dcur;i++)
			//cout<<data[i]<<endl;
		//for(i=0;i<bcur;i++)
			//cout<<buf[i]<<endl;
		for(int i=0;i<dcur-1;i++)
        {
            if(buf[i]=='+')
                data[i+1]+=data[i];
            else if(buf[i]=='-')
                data[i+1]=data[i]-data[i+1];
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout<<data[i]<<endl;
        dcur=0;
        bcur=0;
    }
    return 0;
}