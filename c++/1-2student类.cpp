#include <iostream>
using namespace std;

class student
{
private:
	int number;
	int score;
public:
	void enter()
	{
		cout<<"plese setdate the student's number and score"<<endl;
		cin>>number;
		cin>>score;
	}

	void display()
	{
		cout<<"number is "<<number<<endl;
		cout<<"score is "<<score<<endl;
	}
};

student s1,s2;

int main()
{
	s1.enter();
	s2.enter();
	s1.display();
	s2.display();
	return 0;
}

