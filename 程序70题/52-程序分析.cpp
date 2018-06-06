//52． 读程序，分析它执行后的输出结果，并上机进行测试验证。注意：全局对象I0在执行main前被构造（"诞生"），main结束时"死亡"。
//main中函数级别（局部性）对象I1，在说明时被构造（"诞生"），在函数出口时"死亡"。块级别（auto局部性）对象I2，
//每次入块后都被重新构造（重新分配空间并初始化），出块时结束"生命期"。块级别局部静态对象I3，其作用域局部于块，
//但其"生命期"与全局对象相同，只在第一次遇见时分配空间并初始化。
#include <iostream>
#include <string>
using namespace std;

class MyCla1 
{
	char *str;  
public:
    MyCla1( char *s );
	~MyCla1() 
	{
		cout << "Destructor: Destroying=> " << str << "\n";
		delete str;
	}
    void print()
	{
		cout<<" --- printed by => "<<str<<endl;
	}
};

MyCla1::MyCla1( char *s )
{
    cout << "Constructor: Initializing=>" << s << "\n";
    str=new char[strlen(s)+1];
    strcpy( str, s );
}

MyCla1 I0( "Global I0" );

int main() 
{
    I0.print();    	
	MyCla1 I1( "Function_Local I1" );
    int cond=2;    	
	I1.print();
    while(cond) 
	{
        cout << "In block.\n";
        MyCla1 I2( "Block_Local I2" );   
	    I2.print();
	    static MyCla1 I3( "Static I3" ); 
        cond--;
    }
    cout << "Exited block.\n";
	return 0;
}
