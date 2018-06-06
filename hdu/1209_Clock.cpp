#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double cht(char clock[5]);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        char clock[5][6];
        double angle[5];
        for(int k=0;k<5;k++)
        {
            cin>>clock[k];
            angle[k]=cht(clock[k]);
            //cout<<angle[k]<<endl;
        }
        for(k=0;k<5;k++)
        {
            int c=0;
            for(int j=0;j<5;j++)
                if(angle[k]>angle[j])
                    c++;
                else if(angle[k]==angle[j]&&strcmp(clock[k],clock[j])>0)
                {
                    //cout<<clock[k]<<endl;
                    c++;
                    //cout<<"c="<<c<<endl;
                }
            if(c==2)
                break;
        }
		if(k==5)
			k=0;
        cout<<clock[k]<<endl;
    }
    return 0;
}

double cht(char clock[5])
{
    double h=((clock[0]-48)*10+clock[1]-48)%12;
    double m=(clock[3]-48)*10+clock[4]-48;
    double total=fabs(h*30+0.5*m-m*6);
    //cout<<"total="<<total<<endl;
    if(total>180)
        total=360-total;
    return total;
}
