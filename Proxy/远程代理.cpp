//#include <iostream>
//#include <string>
//using namespace std;
//
//class AbstractServer {
//public:
//	virtual void Request() = 0;
//protected:
//	AbstractServer(){}
//};
//
////�����ķ�����
//class RealServer :public AbstractServer {
//public:
//	void Request() {
//		cout << "����������" << endl;
//	}
//};
//
//class ProxyServer :public AbstractServer {
//public:
//	ProxyServer(string name, string pwd) :m_name(name), m_pwd(pwd) {
//		m_pServer = new RealServer;
//	}
//
//	//�Һ������RealProxyͬ���Ľӿ�
//	void Request() {
//		if ("admin" == m_name && "123" == m_pwd) {
//			cout << "����ɹ�" << endl;
//			cout << "�����������������" << endl;
//			m_pServer->Request();
//			cout << "�������������" << endl;
//		}
//
//		else {
//			cout << "�û����������" << endl;
//		}
//
//	}
//private:
//	string m_name;
//	string m_pwd;
//private:
//	AbstractServer* m_pServer;
//}; 
//
//int main(void) {
//	AbstractServer* pProxy = new ProxyServer("admin", "123");
//	pProxy->Request();
//	system("pause");
//	return 0;
//}