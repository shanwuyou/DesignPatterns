////  ����ģʽ  ����  ���ʿ���  
// //���ļ��� ��ʱ�жϣ����ڸ���ͣ�Ķ����棬û�о����ļ�
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <vector>
//using namespace std;
//
////�зֳ�log:
/////        ������������ʱ�䣬��������
/////map<int,vector<string>>:int ���ϵ���ţ�Ȼ�����ǽ���Щ�� ������|����ʱ��|����������
//map<int, vector<string>> Logs;
////�зֵ��е����룬��| Ϊ�ָ��� �ൽlogs��Ӧ�������
//vector<string> getBugs(string words) {
//	vector<string> results;
//	istringstream ss(words);
//	while (!ss.eof())
//	{
//		string word;
//		getline(ss, word, '|');
//		results.push_back(word);
//	}
//	return results;
//}
//
//bool getLogs() {
//	ifstream in("e:\\tmp\\�����б�.txt");
//	if (!in) {
//		cerr << "�ļ��򿪴���" << endl;
//		system("pause");
//		return -1;
//	}
//
//	string line;
//	int i = 0;
//	while (getline(in, line)) {
//		Logs[i]=getBugs(line);
//		i++;
//	}
//	in.close();
//
//	return 0;
//}
//
//int main(void) {
//	getLogs();//��ȡ��־�ļ�
//	for (int i = 0;i < Logs.size();i++) {
//		cout << "��" << i << "����";
//		for (vector<string>::iterator iter = Logs[i].begin();iter != Logs[i].end();iter++) {
//			cout << (*iter) << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}