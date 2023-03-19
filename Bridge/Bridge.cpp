//�Ž�ģʽ����Ҫ˼�롣 һά�仯���̳У� ��Ϊ�仯���Ž�
// ������ۺϵķ�ʽ
//  ά�ȱ仯 1�������� ��2��ϵͳOS  �������̫�࣬
#include <iostream>
using namespace std;
//
//class Computer {
//public:
//	void run();
//};
//
//class HpWindows7 :public Computer {
//
//};
//class HpWindow8 :public Computer {
//
//};
//
//class HpWindowsX :public Computer {
//
//};

class IOS {
public:
	IOS(){}
	virtual ~IOS()
	{

	}
	virtual void run() = 0;
};

class CWindows :public IOS {
public:
	virtual void run() {
		cout << "Windows ��������" << endl;
	}
};

class CLinux :public IOS {
public:
	virtual void run() {
		cout << "Linux ��������" << endl;
	}
};

class IComputer {
public:
	virtual void Install(IOS *pOS) = 0;
};

class CLenvo :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Lenvo���ڰ�װ����ϵͳ" << endl;
		pOS->run();
	}
};

class CDell :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Dell���ڰ�װ����ϵͳ" << endl;
		pOS->run();
	}
};

class CAcer:public IComputer
{
public:
public:
	virtual void Install(IOS *pOS) {
		cout << "Acer���ڰ�װ����ϵͳ" << endl;
		pOS->run();
	}

private:

};





int main(void) {
	IOS* pWindows = new CWindows;
	IOS* pLinux = new CLinux;

	IComputer* pLenvo = new CLenvo;
	pLenvo->Install(pWindows);
	system("pause");
	return 0;
}

