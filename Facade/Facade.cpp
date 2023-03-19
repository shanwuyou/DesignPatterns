// ����ģʽ  ���ģʽ
// ͨ��һ���ӿ� ȥ���ʶ���ӽӿڣ� 
// Ϊ��ϵͳ��һ��ӿ��ṩһ��ͳһ�ĸ߲�ӿڣ� ʹ��ϵͳ������ʹ��
#include <iostream>
using namespace std;

class Carmera {
public:
	void turnOn() {
		cout << "�������" << endl;
	}
	void turnOff() {
		cout << "����ر�" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "�����ƿ���" << endl;
	}
	void turnOff() {
		cout << "�����ƹر�" << endl;
	}
};
class Sensor {
public:
	void active() {
		cout << "����������" << endl;
	}
	void deactive() {
		cout << "�������ر�" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "����������" << endl;
	}
	void deactive() {
		cout << " �������ر�" << endl;
	}
};

class SecuritFacade {
public:
	SecuritFacade() {
		Carmera* m_pCarmera = new Carmera;
		Light* m_pPLight = new Light;
		Sensor* m_pSensor = new Sensor;
		Alarm* m_pAlaram = new Alarm;
	}
	void active() {
		m_pCarmera->turnOn();
		m_pPLight->turnOn();
		m_pSensor->active();
		m_pAlaram->active();
	}
	void deactive() {
		m_pCarmera->turnOff();
		m_pPLight->turnOff();
		m_pSensor->deactive();
		m_pAlaram->deactive();
	}
private:
	Carmera* m_pCarmera;
	Light* m_pPLight ;
	Sensor* m_pSensor ;
	Alarm* m_pAlaram ;
};
//LOD  �����ط���
int main() {
	SecuritFacade facade;
	

	cout << "-----------����ϵͳ" << endl;
	facade.active();
	//
	cout << "----------�ر�ϵͳ" << endl;
	facade.deactive();
	system("pause");
	return 0;
}