// ͨ����¡�������µĶ����ʵ�У�Ϊ��¡�������µĶ�����ԭ��������
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;
template <class T>
string iToStr(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}
class OrderApi {
public:
	virtual int getOrderProductNum() = 0;
	virtual void setOrderProductNum(int num) = 0;
	virtual string getOrderContent() = 0;
	virtual OrderApi* cloneOrder() = 0;
protected:
	OrderApi() {}
};

class HomeOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "���ζ����Ŀͻ���" + m_strCustomerName + "������id" + m_strProductId + "������������" + iToStr(m_orderProductNum);
	}

	void setCustomerName(string strCustomerName) {
		m_strCustomerName = strCustomerName;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string strProductId) {
		m_strProductId = strProductId;
	}
	string getProductId() {
		return m_strProductId;
	}

	//�ع�
	OrderApi* cloneOrder();
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};

OrderApi* HomeOrder::cloneOrder() {
	
	HomeOrder *pHomeOrder = new HomeOrder;
	pHomeOrder->setCustomerName(m_strCustomerName);
	pHomeOrder->setProductId(m_strProductId);
	pHomeOrder->setOrderProductNum(m_orderProductNum);
	return pHomeOrder;
}


class AboardOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "���ζ����Ŀͻ���" + m_strCustomerName + "������id" + m_strProductId + "������������" + iToStr(m_orderProductNum);
	}

	void setCustomerName(string strCustomerName) {
		m_strCustomerName = strCustomerName;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string strProductId) {
		m_strProductId = strProductId;
	}
	string getProductId() {
		return m_strProductId;
	}
	//�ع�
	OrderApi* cloneOrder();
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};

OrderApi* AboardOrder::cloneOrder() {

	AboardOrder *pHomeOrder = new AboardOrder;
	pHomeOrder->setCustomerName(m_strCustomerName);
	pHomeOrder->setProductId(m_strProductId);
	pHomeOrder->setOrderProductNum(m_orderProductNum);
	return pHomeOrder;
}

class OrderBusiness {
public:
	void saveOrder(OrderApi* pOrder);
};

void OrderBusiness::saveOrder(OrderApi* pOrder) {
	//�ж�һ�£��������������޳���200
	while (pOrder->getOrderProductNum() > 200) {
		//�½�һ������
		OrderApi* pNewOrder = pOrder->cloneOrder();
		pNewOrder->setOrderProductNum(200);
		
		pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
		cout << "�¶�����" << pNewOrder->getOrderContent() << endl;
	}
	//������200��
	cout << "���յĶ�����" << pOrder->getOrderContent() << endl;
}

int main(void) {
	HomeOrder* pHome = new HomeOrder;
	pHome->setOrderProductNum(512);
	pHome->setCustomerName("xcj&dst");
	pHome->setProductId("C++���ģʽ����");
	OrderBusiness* pOb = new OrderBusiness();
	pOb->saveOrder(pHome);
	system("pause");
	return 0;
}

