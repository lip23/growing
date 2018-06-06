#include <iostream>
using namespace std;

const int defaultsize=50;

class bitset
{
public:
	bitset(int sz=defaultsize);//构造函数
	bitset(const bitset & r);//复制构造函数
	~bitset(){delete []bitvector;cout<<"析构成功"<<endl;}//析构函数
	void makeempty(){for(int i=0;i<vectorsize;i++)bitvector[i]=0;}//置空集合
	unsigned short getmember(const int x);//读取集合元素x
	void putmember(const int x,unsigned short v);//将值v送人集合x
	bool addmember(const int x);//加入新成员x
	bool delmember(const int x);//删除老成员x
	bitset & operator = (const bitset & r);//集合r赋值给集合this
	bitset & operator + (const bitset & r);//集合this与集合r的并
	bitset & operator * (const bitset & r);//集合this与集合r的交
	bitset & operator - (const bitset & r);//集合this与集合r的差
	bool contains(const int x);//判断x是否集合this的成员
	bool subset(bitset & r);//判断this是否r的子集
	bool operator == (bitset & r);//判断this与r相等
	friend istream & operator >>(istream & in,bitset & r);//输入
	friend ostream & operator <<(ostream & out,bitset & r);//输出
private:
	int setsize;//集合大小
	int vectorsize;//位数组大小
	unsigned short * bitvector;//存储集合元素的位数组
};