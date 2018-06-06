#include <iostream>
#include <string>
using namespace std;

struct node
{
    node *link[26];
    int total;
    node()
    {
        for(int i=0;i<26;i++)
            link[i]=NULL;
        total=1;
    }
};

class wordtree
{
    public:
    wordtree();
    ~wordtree();
    void enwordtree(const string &);
    int countwordtree(const string &)const;
    private:
    node *front;
    void dele(node *&);//析构时调用的删除结点的函数
};

int main()
{
    string temp;
    wordtree wt;
    while(getline(cin,temp))
    {
        if(temp.empty())break;
        wt.enwordtree(temp);
    }
    while(cin>>temp) cout<<wt.countwordtree(temp)<<endl;
    return 0;
}

wordtree::wordtree()
{
    front=new node();
}

wordtree::~wordtree()
{
    node *del=front;
    dele(del);    
}

void wordtree::dele(node *&cur)
{
    for(int k=0;k<26;k++)
        if(cur->link[k])
            dele(cur->link[k]);
    delete cur;
}

void wordtree::enwordtree(const string &s)
{
    int k=0;
    node *cur=front;
    while(s[k]){
        if(cur->link[s[k]-97])
        {
        	
        	//cout<<s[k]<<endl;
        	//cout<<cur->total<<endl;
            cur=cur->link[s[k]-97];
            ++cur->total;
        }
        else{
            node *newnode=new node();
            cur->link[s[k]-97]=newnode;
            cur=newnode;
            //cout<<s[k]<<endl;
            //cout<<cur->total<<endl;
        }
        k++;
    }
}

int wordtree::countwordtree(const string& s)const
{
    node *cur=front;
    int k=0;
    while(s[k]&&cur->link[s[k]-97]){
        cur=cur->link[s[k]-97];
        k++;
    }
    if(k==s.size())return cur->total;
    return 0;
}
