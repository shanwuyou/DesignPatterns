// ������ģʽ   ������Ϊ�������ı�
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

//����ı��ʽ�����Լ�Context����
//���ڱ��������м����Լ���ǰִ�еĲ�����
class Context {
public:
	int m_value;
	char m_operator;
	Context() :m_value(0), m_operator('\0') {

	}
};
//1+3-2

//��ʾ���б��ʽ�ĳ���ӿ�
class IExpression {
public:
	virtual void Eval(Context* p) = 0;
};

//��ֱ��ʽ��Ԫ��
class Operator :public IExpression {
public:
	Operator(char op) {
		this->m_op = op;
	}
	void Eval(Context *pContext) {
		pContext->m_operator = m_op;
	}
private:
	char m_op;
};

//��ֲ�����
class Operand :public IExpression {
public:
	Operand(int num) {
		this->m_num = num;
	}
	void Eval(Context* pContext) {
		switch (pContext->m_operator)
		{
		case '\0':pContext->m_value = m_num;break;
		case '+':pContext->m_value += m_num;break;
		case '-':pContext->m_value -= m_num;break;
		default:
			break;
		}
	}
private:
	int m_num;
};

class Calculator {
public:
	int Calc(string expression) {
		Context* pCpontext = new Context;
		vector<IExpression*> tree;
		for (int i = 0;i < expression.size();i++) {
			if ((expression[i] == '+') || (expression[i] == '-')) {
				tree.push_back(new Operator(expression[i]));
				printf("��%d��ѹ��ķ�����=%c\n", i, expression[i]);
			}
			else {
				tree.push_back(new Operand((int)(expression[i] - 48)));
				printf("��%d��ѹ���������=%d\n", i,((int)( expression[i]-48)));
			}
		}
		for (vector<IExpression*>::iterator iter = tree.begin();iter != tree.end();iter++) {
			(*iter)->Eval(pCpontext);
			printf("value=%d,oper=%c\n", pCpontext->m_value, pCpontext->m_operator);
		}
		return pCpontext->m_value;
	}
};

int main(void) {
	Calculator* pc = new Calculator;
	cout << "1+4-2=" << pc->Calc("1+4-2") << endl;
	system("pause");
	return 0;
}