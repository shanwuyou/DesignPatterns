//#include <iostream>
//using namespace std;
//
////���˼�룺���Ǹ�����������һ����չ�Ĺ�ϵ���ǲ��Ǻ���
////���ϴ���ԭ����������Ӧ������ȫ����������Ϊ
////���ڼ̳�������ƣ��ر�С�ģ����ǣ���ϴ��ڼ̳�
////��quack��fly�����Ϊһ��������ô���������˽������
//class Duck {
//public:
//	virtual void Quack() = 0;
//	virtual void Display() = 0;
//	virtual void fly() = 0;//fly(int), fly(object)......
//
//protected:
//private:
//};
//
//class DonaladDuck :public Duck {
//public:
//	void Quack() {
//		cout << "��������Ѽ" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly(int param) {
//		cout << "��������Ѽ����Ȼ������ɣ������ҿ������ɻ����������" << endl;
//	}
//};
////��һ�������������ƺ���̫��ô���ࡣ����
//class RuberDuck : public Duck {
//public:
//	void Quack() {
//		
//	}
//	void Display() {
//		Quack();
//	}
//};
//
//class WigeonDuck : public Duck {
//public:
//	void Quack() {
//		cout << "����СҰѼ" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly() {
//		cout << "������������ɰ���" << endl;
//	}
//};