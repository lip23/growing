#include <iostream>
using namespace std;

const int defaultsize=50;

class bitset
{
public:
	bitset(int sz=defaultsize);//���캯��
	bitset(const bitset & r);//���ƹ��캯��
	~bitset(){delete []bitvector;cout<<"�����ɹ�"<<endl;}//��������
	void makeempty(){for(int i=0;i<vectorsize;i++)bitvector[i]=0;}//�ÿռ���
	unsigned short getmember(const int x);//��ȡ����Ԫ��x
	void putmember(const int x,unsigned short v);//��ֵv���˼���x
	bool addmember(const int x);//�����³�Աx
	bool delmember(const int x);//ɾ���ϳ�Աx
	bitset & operator = (const bitset & r);//����r��ֵ������this
	bitset & operator + (const bitset & r);//����this�뼯��r�Ĳ�
	bitset & operator * (const bitset & r);//����this�뼯��r�Ľ�
	bitset & operator - (const bitset & r);//����this�뼯��r�Ĳ�
	bool contains(const int x);//�ж�x�Ƿ񼯺�this�ĳ�Ա
	bool subset(bitset & r);//�ж�this�Ƿ�r���Ӽ�
	bool operator == (bitset & r);//�ж�this��r���
	friend istream & operator >>(istream & in,bitset & r);//����
	friend ostream & operator <<(ostream & out,bitset & r);//���
private:
	int setsize;//���ϴ�С
	int vectorsize;//λ�����С
	unsigned short * bitvector;//�洢����Ԫ�ص�λ����
};