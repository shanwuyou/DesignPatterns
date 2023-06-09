// 具体的算法 抽象出来，形成一个算法类，形成一系列算法，
// 让这些算法可以相互替换
// 解决直接用继承带来的不足

// 案列：
#include <iostream>
using namespace std;

//设计思想：我们父类和子类就是一个扩展的关系？是不是合适
//里氏代换原则：子类对象就应该能完全替代父类的行为
//对于继承这样设计，特别小心，我们：组合大于继承
//把quack和fly抽象成为一个对象，那么这个问题就了解决方案


//////////////////////////
//完成了将“动作”抽象成“对象”
class QuackBehavior {
public:
	virtual void quack() = 0;
protected:
	QuackBehavior(){} 
};
class FlyBehavior {
public:
	virtual void fly() = 0;
protected:
	FlyBehavior(){}
};

class FlyWithRocket :public FlyBehavior {
	void fly() {
		cout << "做着火箭飞" << endl;
	}
};

class FlyWithWings :public FlyBehavior {
	void fly() {
		cout << "我有翅膀可以自己飞" << endl;
	}
};

class FlyWithNoWay :public FlyBehavior {
	void fly() {
		cout << "我根本就会飞" << endl;
	}
};

class ZhiZhiQuack :public QuackBehavior {
public:	void quack() {
	cout << "吱吱" << endl;
	}
};

class PersonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "我是唐唐姥姥" << endl;
	}
};

class WigeonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "丑小鸭变天鹅" << endl;
	}
};

/////////////////////////////////////
//Duck has a Quack 
//     has a Fly
class Duck {

public:
	
	virtual void Display() = 0;
	void setFlyBehavior(FlyBehavior* fb) {
		m_pFly = fb;
	}
	void setQuackBehavior(QuackBehavior* qb) {
		m_pQuack = qb;
	}

	virtual void perfomrFly() {
		m_pFly->fly();

		//if (is 唐老鸭） {唐老鸭的飞行
		//if (is 小黄鸭）{小黄鸭的飞行.....
	}

	virtual void performQuack() {
		m_pQuack->quack();
	}
protected:
	QuackBehavior *m_pQuack;
	FlyBehavior *m_pFly;
private:
};
//DonaladDuck is Duck
class DonaladDuck :public Duck {
public:
	DonaladDuck() {
		m_pFly = new FlyWithRocket();//某一个FlyBehavior的实例
		m_pQuack = new PersonQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};
//第一个困境：子类似乎不太那么像父类。。。
class RuberDuck : public Duck {
public:
	RuberDuck() {
		m_pFly = new FlyWithNoWay();
		m_pQuack = new ZhiZhiQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
};

class WigeonDuck : public Duck {
public:
	WigeonDuck() {
		m_pFly = new FlyWithWings;
		m_pQuack = new WigeonQuack;
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};

int main() {
	DonaladDuck *pDonlad = new DonaladDuck;
	pDonlad->Display();
	system("pause");
	return 0;
}
//
class XiaoFeiXia :public Duck {
	//
	//m_pFly = new FlyWithHotPollun()
};