//  ������
//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//template <class T>
//string MyConvertToString(T value) {
//	stringstream ss;
//	ss << value;
//	return ss.str();
//}
//class FeeRequest {
//public:
//	string requestToPrjManager(double fee) {
//		string strTemp = "";
//		if (fee < 500) {
//			strTemp = prjHandle(fee);
//		}else if (fee < 1000) {
//			strTemp = depHandle(fee);
//		}else if (fee >= 1000) {
//			strTemp = CEOHandle(fee);
//		}
//		return strTemp;
//	}
//private:
////��Ŀ����
//	string prjHandle(double fee) {
//		if (fee >= 0 && fee < 500) {
//			return "��Ŀ����ͬ��" + MyConvertToString(fee) + "���";
//		}
//		else {
//			return "��Ŀ����ͬ��" + MyConvertToString(fee) + "���";
//		}
//	}
//
//	string depHandle(double fee) {
//		if (fee >= 500 && fee < 1000) {
//			return "���ž���ͬ��" + MyConvertToString(fee) + "���";
//		}
//		else {
//			return "���ž���ͬ��" + MyConvertToString(fee) + "���";
//		}
//	}
//	
//	string CEOHandle(double fee) {
//		if (fee >= 1000) {
//			return "CEOͬ��" + MyConvertToString(fee) + "���";
//		}
//		
//	}
//	
//};
//
//int main(void) {
//	FeeRequest* pRequest = new FeeRequest;
//	cout << pRequest->requestToPrjManager(300)<<endl;
//	cout << pRequest->requestToPrjManager(512) << endl;
//	cout << pRequest->requestToPrjManager(1024) << endl;
//	system("pause");
//	return 0;
//}
