//#include <iostream>
//using namespace std;
//
//class FrameApi {
//public:
//	virtual void draw() = 0;
//protected:
//	FrameApi() {};
//};
//
//class LayoutApi {//分辨率的布局器
//public:
//	virtual void installFrame() = 0;
//protected:
//	LayoutApi(){}
//};
//
////pc上的Frame
//class ComputerFrame :public FrameApi {
//public:
//	ComputerFrame(int pins) : m_pins(pins) {
//
//	}
//	void draw() {
//		cout << "现在是pc机的Frame,我适用的分辨率是" << m_pins<<endl;
//	}
//private:
//	int m_pins;
//};
//
//class MobileFrame :public FrameApi {
//public:
//	MobileFrame(int pins):m_pins(pins){}
//	void draw() {
//		cout << "现在是Mobile的Frame,我使用的分辨率是" << m_pins<<endl;
//	}
//
//private:
//	int m_pins;
//};
//
////高分辨率的布局
//class HighLayout :public LayoutApi {
//public:
//	HighLayout(int FrameAdpaterPins):m_FrameAdpaterPins(FrameAdpaterPins){}
//	void installFrame() {
//		cout << "现在是在PC环境下，我们使用的高分辨率布局" << m_FrameAdpaterPins << endl;
//	}
//
//private:
//	int m_FrameAdpaterPins;
//};
//
////低分辨率的布局
//class LowLayout :public LayoutApi {
//public:
//	LowLayout(int FrameAdpaterPins) :m_FrameAdpaterPins(FrameAdpaterPins) {}
//	void installFrame() {
//		cout << "现在是在Mobile环境下，我们使用的低分辨率布局" << m_FrameAdpaterPins << endl;
//	}
//
//private:
//	int m_FrameAdpaterPins;
//};
//
////创建产品的简单工厂
//class FrameFactory {
//public:
//	static FrameApi* createFrame(int type) {
//		if (type == 1)
//			return new ComputerFrame(1024);
//		if (type == 2)
//			return new MobileFrame(800);
//		return nullptr;
//	}
//};
//
//class LayoutFactory {
//public:
//	static LayoutApi* createLayout(int type) {
//		if (type == 1)
//			return new HighLayout(1024);
//		if (type == 2)
//			return new LowLayout(800);
//		return nullptr;
//	}
//};
//
//class GUIEngineer {
//public:
//	//FrameType:是用来表述选择Frame控件的类型
//	//LayoutType:是用来表述选择布局管理器的类型
//	void prepareDraw(int FrameType, int LayoutType) {
//		this->pFrame = FrameFactory::createFrame(FrameType);
//		this->pLayout = LayoutFactory::createLayout(LayoutType);
//		pFrame->draw();
//		pLayout->installFrame();
//	}
//private:
//	FrameApi* pFrame;
//	LayoutApi* pLayout;
//};
//
//int main(void) {
//	GUIEngineer* pEng = new GUIEngineer;
//	pEng->prepareDraw(1, 2);
//	system("pause");
//	return 0;
//}