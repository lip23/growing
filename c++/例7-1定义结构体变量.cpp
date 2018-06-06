#include <iostream>
#include <string>
using namespace std;
struct student
{
	int num;
	string name;
	char sex;
	int birthday;
	int grade;
};

int main()
{
	student s1,s2;
	cout<<"please put student1's num name sex birthday garde"<<endl;
	cin>>s1.num>>s1.name>>s1.sex>>s1.birthday>>s1.grade;
	s2=s1;
	cout<<"student2's date is :"<<endl;
	cout<<s2.num<<" "<<s2.name<<" "<<s2.sex<<" "<<s2.birthday<<" "<<s2.grade<<endl;
	return 0;
}

