#include <iostream>
#include<string>
#include "DynOBJ.h"
using namespace std;

class Api {
public:
	virtual void test(string s) = 0;
protected:
	Api(){}
};


class ImpleOne :public Api {
public:
	void test(string s) {
		cout << "������One��ִ��" << s;
	}
};

class ImpleTwo :public Api {
public:
	void test(string s) {
		cout << "������Two��ִ��" << s;
	}
};

class Factory {
public:
	static Api* createApi(int type) {

		Api* pApi = nullptr;
		if (type == 1) {
			pApi = new ImpleOne();
		}
		if (type == 2) {
			pApi = new ImpleTwo();
		}
		return pApi;
	}

	static Api* createApi() {
		return new ImpleOne();
	}
};


/**
�������1������ʵ�ִ����ݿ����Ĺ���
�������2������ʵ�ִ��ı��ļ�����Ĺ���
*/
int main1(void) {
	Api* pApi = Factory::createApi(2);//�ͻ��ˣ�����֪��������ϸ��

	pApi->test("������ʹ�ü򵥹��������ع�");
	Api* pApiEx = Factory::createApi();
	system("pause");
	return 0;
}
//ʵ���˿ͻ��˵��ú�implOne��implTwo�Ľ����
//factory��ʵ���˱仯����

//���������
/*
static Api* createApi() {
return new ImpleOne();//ImplOne,ImplTwo?

}
��̬����
*/
namespace test1 {
	class ImpleTwoHelper {
	public:
		ImpleTwoHelper() {
			CObjectFactory::registerClass("ImpleTwo", ImpleTwoHelper::createObjFunc);
		}
		static void* createObjFunc() {
			return new ImpleTwo;
		}
	};
	// ���Զ�̬������  ��һ�������꣬ʵ�ָ���
	int main2(void) {
		// ��������
		ImpleTwo* pTwo = static_cast<ImpleTwo*> (ImpleTwoHelper::createObjFunc());
		pTwo->test("���Զ�̬����");
		return 0;
	}
};

REG_CLASS(ImpleTwo)
int main3(void) {
	ImpleTwo* pTwo = static_cast<ImpleTwo*>(CObjectFactory::creatObject("ImpleTwo"));
	pTwo->test("RegClass");
	system("pause");
	return 0;
}

class AutoFactory{
public:
	static Api* createApi() {
		Api* pApi = nullptr;
		pApi = static_cast<Api*>(CObjectFactory::creatObject("ImpleTwo"));
		return pApi;
	}
};

int main() {
	Api* pApi = AutoFactory::createApi();
	pApi->test("������ȫ��֪��������Ķ�����");
	system("pause");
	return 0;
}
