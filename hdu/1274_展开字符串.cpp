#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <stack>
using namespace std;

int main()
{
	int n;
	while(n--)
	{
		string temp;
		cin>>temp;
		stack<int> pos_data;
		stack<int> count_data;
		string result_data;
		int k=0;
		while(temp[k]){
			if(isalpha(temp[k])){
				do{
					result_data.append(1,temp[k++]);
				}while(isalpha(temp[k]))
			}
			if(temp[k]=='('&&(k==0||!isdigit(temp[k-1]))){
				pos_data.push(k);
				count_data.push(1);
			}
			else if(isdigit(temp[k])){
				int sum=0;
				do{
					sum=sum+temp[k++]-'0';
				}while(isdigit(temp[k]))
				if(temp[k]=='('){
					pos_data.push(k);
					count_data.push(sum);
				}
				else
					result_data.append(sum,temp[k])
			}
			if(temp[k]==')'){
				int t1=pos_data.top();
				pos_data.pop();
				int t2=count_data.top();
				count_data.pop();
				
			}
			
			
		}
		
		
		
