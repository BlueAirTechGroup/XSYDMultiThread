#include <iostream>
#include "XSYDMultiThread.h"
using namespace std;
unsigned int Hello(PVOID SB){
		std::cout << "我是英俊潇洒风流倜傥的子线程" << std::endl;
		std::cout << "我的线程ID为:" << GetCurrentThreadId() << std::endl;
		return 0;
}
 
int main(int argc,char** args){
	std::cout << "牛逼的主线程爸爸启动了" << std::endl; //输出启动文本 
	std::cout << "线程ID:" << GetCurrentThreadId() << std::endl; //输出自己的线程ID 
	clsXSYDWinMT *MyMT = new clsXSYDWinMT(); //设置一个XSYDMT类模块 
	HANDLE MyID = MyMT->AddThread(Hello); //添加线程,执行Hello()函数 
	HANDLE MyID2 = MyMT->AddThread(Hello);
	HANDLE MyID3 = MyMT->AddThread(Hello);
	HANDLE MyID4 = MyMT->AddThread(Hello);
	MyMT->WaitForThread(MyID); //主线程等待子线程退出后再进行下一步动作
	system("pause");
	return 0; 
}
