// ������ģʽ�� ��������
// �������� �����Լ������ָ��p����ʼ��p�ĺ��� 
// һ���ڵ��ú����У�������������
// Ȩ�޼�飬 Ȩ������
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
string MyConvertToString(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

//����ĳ�����,�淶�˻��Ĵ������������
class Handle {
public:
	void setSuccessor(Handle *pSuccessor){
		this->m_pHandle = pSuccessor;
	}
	virtual string handleFeeRequest(double fee) = 0;
protected:
	Handle* m_pHandle;
};

class PrjManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee < 500) {
			strTemp = "��Ŀ����ͬ��" + MyConvertToString(fee) + "����";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;
		
	}
};

class DepManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee>=500 &&fee < 1000) {
			strTemp = "���ž���ͬ��" + MyConvertToString(fee) + "����";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;

	}
};

class CEOManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee >= 1000) {
			strTemp = "CEO����ͬ��" + MyConvertToString(fee) + "����";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;

	}
};
int main(void) {
	//��Ҫ��װ���ǵ�������
	Handle* pH1 = new PrjManager;
	Handle* pH2 = new DepManager;
	Handle* pH3 = new CEOManager;
	pH1->setSuccessor(pH2);
	pH2->setSuccessor(pH3);
	cout << pH1->handleFeeRequest(128) << endl;
	cout << pH1->handleFeeRequest(512) << endl;
	cout << pH1->handleFeeRequest(1024) << endl;
	system("pause");
	return 0;
}
