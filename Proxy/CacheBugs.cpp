//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <vector>
//using namespace std;
//
////切分成log:
/////        故障名，故障时间，故障描述
/////map<int,vector<string>>:int 故障的序号，然后我们将这些（ 故障名|故障时间|故障描述）
//map<int, vector<string>> Cache;
//
//class BugManager {
//public:
//	virtual void getBug() = 0;
//};
//
//class RealBugModel {
//public:
//	void getBugs() {
//		//从文件读取，并且将故障信息封装进入Cache中
//		ifstream in("e:\\tmp\\故障列表.txt");
//		if (!in) {
//			cerr << "文件打开错误" << endl;
//			system("pause");
//			
//		}
//		string line;
//		int i = 0;
//		while (getline(in, line)) {
//			Cache[i] = getCache(line);
//			i++;
//		}
//		in.close();
//	}
//private:
//	vector<string> getCache(string words) {
//		vector<string> results;
//		istringstream ss(words);
//		while (!ss.eof())
//		{
//			string word;
//			getline(ss, word, '|');
//			results.push_back(word);
//		}
//		return results;
//	}
//};
//
//class ProxyBugModel {
//public:
//	ProxyBugModel() :m_reload(false) {
//
//	}
//	void getBugs() {
//		if (m_reload) {
//			cout << "这是从缓存里面获取的" << endl;
//			showBugs();
//		}
//		else {
//			cout << "这是真实的数据" << endl;
//			(new RealBugModel())->getBugs();
//			m_reload = true;
//			showBugs();
//		}
//	}
//private:
//	void showBugs() {
//		for (int i = 0;i < Cache.size();i++) {
//			cout << "第" << i << "行是";
//			for (vector<string>::iterator iter = Cache[i].begin();iter != Cache[i].end();iter++) {
//				cout << (*iter) << " ";
//			}
//			cout << endl;
//		}
//	}
//private:
//	bool m_reload;//如果reload为真，表示，这个是从缓存里面拿的，否则，我们请求真正的realbug对象
//};
//
//
//
//int main(void) {
//	ProxyBugModel* p = new ProxyBugModel();
//	for (int i = 0;i < 5;i++) {
//		cout << "第" << i << "次请求" << endl;
//		p->getBugs();
//	}
//	
//	system("pause");
//	return 0;
//}