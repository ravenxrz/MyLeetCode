/**
 * Created by raven on 2020/9/10.
 * ���ʽ��ֵ
 * �����ϵ��㷨������ͬ�������Լ������д��
 */
#include "../˳��ջ/sq_stack.cpp"
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

int operate(int num1, int num2, char op);

int precedence(char op)
{
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int eval(const string &expression)
{
    /* ���������ջ�Ͳ�����ջ */
    sqstack<int> numstack;
    sqstack<char> opstack;
    int num1, num2;
    char op;
    char cur;
    
    for (size_t i = 0; i < expression.length(); i++) {
        /*  �����ո� */
        cur = expression.at(i);
        if (cur == ' ') continue;
        
        /* �������������Ҫѹ�� */
        if (isdigit(cur)) {
            int val = 0;
            while (i < expression.length() && isdigit(expression.at(i))) {
                val = val * 10 + (int) (expression.at(i) - '0');
                i++;
            }
            numstack.push(val);
            if(i >= expression.length()) break;
            if(!isdigit(expression.at(i))) i--;        /* ��ԭ���� */
        }
        /* ���Ŵ��� */
        else if (cur == '(') {
            opstack.push(cur);
        } else if (cur == ')') {
            /* ������( xxx )������������ */
            opstack.pop(op);
            while(!opstack.isempty() && op != '(') {
                numstack.pop(num2);
                numstack.pop(num1);
                numstack.push(operate(num1, num2, op));
                opstack.pop(op);
            }
            numstack.gettop(num1);
        }
            /* ��������� */
        else {
            if(!opstack.isempty()){
                opstack.gettop(op);
                if (precedence(op) >= precedence(cur)) {
                    numstack.pop(num2);
                    numstack.pop(num1);
                    opstack.pop(op);
                    numstack.push(operate(num1, num2, op));
                }
            }
            opstack.push(cur);
        }
    }
    
    /* ����ʣ���� */
    while(!opstack.isempty()){
        numstack.pop(num2);
        numstack.pop(num1);
        opstack.pop(op);
        numstack.push(operate(num1, num2, op));
    }
    numstack.pop(num1);
    return num1;
}

int operate(int num1, int num2, char op)
{
    int val = -1;
    switch (op) {
        case '+':
            val = num1 + num2;
            break;
        case '-':
            val = num1 - num2;
            break;
        case '*':
            val = num1 * num2;
            break;
        case '/':
            val = num1 / num2;
            break;
        default:
            cerr << "����ȷ�ı��ʽ" << "\n";
            exit(ERROR);
    }
    return val;
}

int main()
{
    cout << eval("(4*5+3)+(3*10/2+1)*3*(4+2/2)") << "\n";
    return 0;
}