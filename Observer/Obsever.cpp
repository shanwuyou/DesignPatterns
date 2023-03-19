// �۲���ģʽ
// ��������1�Զ� ��ϵ�� ��һ���������仯��ʱ�������������ж���
// ����õ�֪ͨ
#include <iostream>
#include <vector>
#include <string>
using namespace std;

///����һ��Subject����
///�۲���
class Observer {
public:
	virtual void update(string m_Temp, string m_Humi) = 0;
protected:
	Observer() {}
};
class Subject {
public:
	virtual void registerObserver(Observer* pObj)=0;
	virtual void removeObserver(Observer* pObj)=0;
	virtual void noitfyObserver()=0;
protected:
	Subject(){}
};

class WeatherData :public Subject {
public:
	WeatherData(string Temp, string Humi) : m_Temp(Temp), m_Humi(Humi) {
	}
	void registerObserver(Observer* pObj) {
		m_observers.push_back(pObj);
	}
	void removeObserver(Observer* pObj) {
		auto iter = find(m_observers.begin(), m_observers.end(), pObj);
		if (iter != m_observers.end()) {
			m_observers.erase(iter);
		}
	}
	void noitfyObserver() {
		//�����������Observer��update����
		for (vector<Observer*>::iterator iter = m_observers.begin();iter != m_observers.end();iter++) {
			(*iter)->update(m_Temp, m_Humi);
			
		}
	}

	void setData(string Temp, string Humi) {
		m_Temp = Temp;
		m_Humi = Humi;
		noitfyObserver();
	}
private:
	vector<Observer*> m_observers;
	string m_Temp;//�¶�
	string m_Humi;//ʪ��
};




//CocreteObserver
class PCDisplay:public Observer {
public:
	void update(string m_Temp, string m_Humi) {
		cout << "����PC�˵���ʾGUI,��ǰ���¶�Ϊ" << m_Temp << "ʪ��Ϊ" << m_Humi << endl;
	}

	PCDisplay(WeatherData* pWeatherData) {
		m_pWeatherData = pWeatherData;
		m_pWeatherData->registerObserver(this);
	}
private:
	WeatherData* m_pWeatherData;
};



class MobileDisplay :public Observer {
public:
	void update(string m_Temp, string m_Humi) {
		cout << "����Mobile�˵���ʾGUI,��ǰ���¶�Ϊ" << m_Temp << "ʪ��Ϊ" << m_Humi << endl;
	}

	MobileDisplay(WeatherData* pWeatherData) {
		m_pWeatherData = pWeatherData;
		m_pWeatherData->registerObserver(this);
	}
private:
	WeatherData* m_pWeatherData;
};


int main(void) {
	WeatherData* pWD = new WeatherData("22C", "65%");
	PCDisplay* pPCDisplay = new PCDisplay(pWD);
	MobileDisplay* pMobile = new MobileDisplay(pWD);

	pWD->setData("38C", "55%");
	pWD->removeObserver(pMobile);
	pWD->setData("31", "44%");
	
	system("pause");
	return 0;
}