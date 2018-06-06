#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string corfile,usefile,cortest,usetest;
        string input;
        cin>>input;
        while(getline(cin,input)&&input!="END"){
            corfile.append(input);
            corfile.append(1,'\n');
        }
        cin>>input;
        while(getline(cin,input)&&input!="END"){
            usefile.append(input);
            usefile.append(1,'\n');
        }
        if(corfile==usefile)cout<<"Accepted\n";
        else{
            istringstream stream(corfile),streamu(usefile);
            string temp;
            while(stream>>temp) cortest.append(temp);
            while(streamu>>temp) usetest.append(temp);
            if(cortest==usetest)cout<<"Presentation Error\n";
            else cout<<"Wrong Answer\n";
        }
    }
    return 0;
}
