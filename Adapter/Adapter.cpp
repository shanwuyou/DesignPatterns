//#include <iostream>
//using namespace std;
//class ThreePhaseOutlet {
//public:
//	void doThreePhasePlug() {
//		cout << "�����ͷ����" << endl;
//	}
//};
//
//class TwoPhaseOutlet {
//public:
//	virtual void doPlug() = 0;
//};
//
//class OutletConverter :public TwoPhaseOutlet, public ThreePhaseOutlet {
//public:
//	void doPlug() {
//		doConvertor();
//		doThreePhasePlug();
//	}
//	void doConvertor() {
//		cout << "�������ڽ������ͷתΪ�����ͷ" << endl;
//	}
//};
//
////�������䣬�����Ը������һЩ
//class OutletObjConvertor :public TwoPhaseOutlet {
//public:
//	OutletObjConvertor(ThreePhaseOutlet* pOut) :m_pOut(pOut) {
//
//	}
//	void doPlug() {
//		doConvert();
//		m_pOut->doThreePhasePlug();
//	}
//	void doConvert() {
//		cout << "�������ڶ�һ�������ͷ�������ת��" << endl;
//	}
//private:
//	ThreePhaseOutlet* m_pOut;
//};
//
//int main(void) {
//	/*TwoPhaseOutlet* pOutlet = new OutletConverter();
//	pOutlet->doPlug();*/
//	TwoPhaseOutlet* pOutlet = new OutletObjConvertor(new ThreePhaseOutlet);
//	pOutlet->doPlug();
//	system("pause");
//	return 0;
//}