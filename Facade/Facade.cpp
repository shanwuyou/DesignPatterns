// 门面模式  外观模式
// 通过一个接口 去访问多个子接口， 
// 为子系统的一组接口提供一个统一的高层接口， 使子系统更容易使用
#include <iostream>
using namespace std;

class Carmera {
public:
	void turnOn() {
		cout << "相机启动" << endl;
	}
	void turnOff() {
		cout << "相机关闭" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "照明灯开启" << endl;
	}
	void turnOff() {
		cout << "照明灯关闭" << endl;
	}
};
class Sensor {
public:
	void active() {
		cout << "传感器启动" << endl;
	}
	void deactive() {
		cout << "传感器关闭" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "报警器启动" << endl;
	}
	void deactive() {
		cout << " 报警器关闭" << endl;
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
//LOD  迪米特法则
int main() {
	SecuritFacade facade;
	

	cout << "-----------启动系统" << endl;
	facade.active();
	//
	cout << "----------关闭系统" << endl;
	facade.deactive();
	system("pause");
	return 0;
}