/*64． 利用get与put成员函数完成文件的拷贝工作，假设被拷贝的"源文件"以及拷贝到的"目的文件"的名字与路径均由命令行参数来提供。
下面给出实现程序"构架"：
void main(int argc, char* argv[ ]) {
	…
ifstream fin(argv[1]);  	//命令行参数1提供被拷贝的"源文件"
ofstream fout(argv[2]);  	//命令行参数2提供拷贝到的"目的文件"
char ch;
fin.get(ch);
while(!fin.eof()){		//从头读到文件结束（当前符号非文件结束符时继续）
		fout.put(ch);  		//对流fout进行写
		fin.get(ch);   		//对流fin进行读
}
…
}
注意：在VC6集成开发环境下，运行这种main带参数的程序之前，要使用菜单命令，通过如下步骤来设置命令行参数（程序参数）：
Project → Settings → Debug → 在"Program arguments:"框内，输入以空格分割的各命令行参数，
如，"aa.cpp  bb.cpp"（该框为空时，表示没有命令行参数）→ OK。*/

#include <iostream>
using namespace std;

