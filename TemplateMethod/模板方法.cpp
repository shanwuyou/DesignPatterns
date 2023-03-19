//  �Բ�ͬ����֮�仮���������㷨�ĳ��� �ȶ������ΪҲ�����
// ���������Ϊ��Լ����
#include <iostream>
using namespace std;

//PC�����ֻ���ƽ��
class MakeOrder {
public:
	//virtual void startOrder() =0;��һ��
	//���Ӻ�����ģ�巽��
	virtual void startOrder() {
		cout << "�¶�����" << endl;
	}
	virtual void replyStart()=0;
	//.....
	virtual void finishOrder()=0;
	virtual void replyFinish()=0;
	//ģ��ģʽ
	void make() {
		startOrder();
		replyStart();
		finishOrder();
		replyFinish();
	}
protected:
	MakeOrder(){}
};

class Fanuc :public MakeOrder {
public:
	void startOrder() {
		cout << "Fanuc��ʼ���ܶ���" << endl;
	}
	void replyStart() {
		cout << "Fanuc����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	//.....
	 void finishOrder() {
		 cout << "����Fanuc�����Ѿ���ɣ����ƽ��¸�������������" << endl;
	}
	 void replyFinish() {
		 cout << "Fanuc�����ź��Ѿ��ʹ�����ƽ��¸�������������" << endl;
	 }
};

class Sims :public MakeOrder {
public:
	void startOrder() {
		cout << "Sims��ʼ���ܶ���" << endl;
	}
	void replyStart() {
		cout << "Sims����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	//.....
	void finishOrder() {
		cout << "����Sims�����Ѿ���ɣ����ƽ��¸�������������" << endl;
	}
	void replyFinish() {
		cout << "Sims�����ź��Ѿ��ʹ�����ƽ��¸�������������" << endl;
	}
};

class Mits :public MakeOrder {
public:
	
	void replyStart() {
		cout << "Sims����Ԥ�����뽫��̶��������Ŷ�" << endl;
	}
	//.....
	void finishOrder() {
		cout << "����Sims�����Ѿ���ɣ����ƽ��¸�������������" << endl;
	}
	void replyFinish() {
		cout << "Sims�����ź��Ѿ��ʹ�����ƽ��¸�������������" << endl;
	}
};

int main(void) {
	//MakeOrder* pMakeOrder = new Fanuc;
	//pMakeOrder->make();
	MakeOrder* pMakeOrder = new Mits;
	pMakeOrder->make();
	system("pause");
	return 0;
}