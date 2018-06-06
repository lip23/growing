#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct student
{
	string name;
	int grade;
};

int main()
{
	int n;
	bool cmp(student,student);
	while(cin>>n)
	{
		//student *sstu=new student[n];
		//student *ststu=new student[n];
		vector<student> ss,sts;
		student temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp.name>>temp.grade;
			sts.push_back(temp);
		}
		stable_sort(sts.begin(),sts.end(),cmp);
		for(i=0;i<n;i++)
		{
			cin>>temp.name>>temp.grade;
			ss.push_back(temp);
		}
		//for(i=0;i<n;i++)
				//cout<<sts[i].name<<' '<<sts[i].grade<<endl;
		bool psc=true;
		bool pst=true;
		for(i=0;psc&&i<n;i++)
		{
			if(ss[i].grade!=sts[i].grade)
			{
				psc=false;
				break;
			}
			if(ss[i].name!=sts[i].name)
				pst=false;
		}
		if(psc&&pst)
			cout<<"Right"<<endl;
		else if(psc&&!pst)
			cout<<"Not Stable"<<endl;
		else if(!psc)
			cout<<"Error"<<endl;
		if(!psc||!pst)
			for(i=0;i<n;i++)
				cout<<sts[i].name<<' '<<sts[i].grade<<endl;
	}
	return 0;
}

bool cmp(student s1,student s2)
{
	return s1.grade>s2.grade;
}
