//52�� �����򣬷�����ִ�к�������������ϻ����в�����֤��ע�⣺ȫ�ֶ���I0��ִ��mainǰ�����죨"����"����main����ʱ"����"��
//main�к������𣨾ֲ��ԣ�����I1����˵��ʱ�����죨"����"�����ں�������ʱ"����"���鼶��auto�ֲ��ԣ�����I2��
//ÿ�����󶼱����¹��죨���·���ռ䲢��ʼ����������ʱ����"������"���鼶��ֲ���̬����I3����������ֲ��ڿ飬
//����"������"��ȫ�ֶ�����ͬ��ֻ�ڵ�һ������ʱ����ռ䲢��ʼ����
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
