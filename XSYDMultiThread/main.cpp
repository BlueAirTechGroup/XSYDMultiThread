#include <iostream>
#include "XSYDMultiThread.h"
using namespace std;
unsigned int Hello(PVOID SB){
		std::cout << "����Ӣ�������������ε����߳�" << std::endl;
		std::cout << "�ҵ��߳�IDΪ:" << GetCurrentThreadId() << std::endl;
		return 0;
}
 
int main(int argc,char** args){
	std::cout << "ţ�Ƶ����ְ̰߳�������" << std::endl; //��������ı� 
	std::cout << "�߳�ID:" << GetCurrentThreadId() << std::endl; //����Լ����߳�ID 
	clsXSYDWinMT *MyMT = new clsXSYDWinMT(); //����һ��XSYDMT��ģ�� 
	HANDLE MyID = MyMT->AddThread(Hello); //����߳�,ִ��Hello()���� 
	HANDLE MyID2 = MyMT->AddThread(Hello);
	HANDLE MyID3 = MyMT->AddThread(Hello);
	HANDLE MyID4 = MyMT->AddThread(Hello);
	MyMT->WaitForThread(MyID); //���̵߳ȴ����߳��˳����ٽ�����һ������
	system("pause");
	return 0; 
}
