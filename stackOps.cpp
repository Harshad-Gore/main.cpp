#include <iostream>
using namespace std;
#define MAX 5

class stack
{
    string st[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if (top == MAX - 1)
            return 1;
        else
            return 0;
    }

    void push(string ele)
    {
        if (isFull())
            cout << "Stack is full\n";
        else
        {
            top++;
            st[top] = ele;
        }
    }

    string pop()
    {
        if (!isEmpty())
        {
            string temp = st[top];
            top--;
            return temp;
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }

    string stacTop()
    {
        if (!isEmpty())
            return st[top];
        else
            cout << "Stack is empty\n";
    }

    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }

    string prefixToInfix(string prefix)
    {
        stack s;
        int len = prefix.length();
        for (int i = len - 1; i >= 0; i--)
        {
            if (isOperand(prefix[i]))
            {
                s.push(string(1, prefix[i]));
            }
            else
            {
                string op1 = s.pop();
                string op2 = s.pop();
                string exp = "(" + op1 + prefix[i] + op2 + ")";
                s.push(exp);
            }
        }
        return s.pop();
    }
    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    string infixToPostfix(string infix)
    {
        stack s;
        string postfix = "";
        for (char &ch : infix)
        {
            if (isOperand(ch))
            {
                postfix += ch;
            }
            else if (ch == '(')
            {
                s.push(string(1, ch));
            }
            else if (ch == ')')
            {
                while (!s.isEmpty() && s.stacTop() != "(")
                {
                    postfix += s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.isEmpty() && precedence(s.stacTop()[0]) >= precedence(ch))
                {
                    postfix += s.pop();
                }
                s.push(string(1, ch));
            }
        }
        while (!s.isEmpty())
        {
            postfix += s.pop();
        }
        return postfix;
    }
    int evaluatePostfix(string postfix)
    {
        int op_1, op_2, result;
        string res;
        stack s;
        for (int i = 0; i <= postfix.length() - 1; i++)
        {
            if (isOperand(postfix[i]))
            {
                string op2 = s.pop();
                string op1 = s.pop();
                stringstream;
            }
        }
    }
    void postfixEval()
    {
        string postfixNum;
        stack s;
        cout << "Enter postfix expression: ";
        getline(cin, postfixNum);
        int len = postfixNum.length();
        for (int i = 0; i < len; i++)
        {
            if (postfixNum[i] == ' ')
            {
                continue;
            }
            else if (isdigit(postfixNum[i]))
            {
                int operand = 0;
                while (isdigit(postfixNum[i]))
                {
                    operand = operand * 10 + (postfixNum[i] - '0');
                    i++;
                }
                i--;
                s.push(to_string(operand));
            }
        }
    }
};
int main()
{
    stack s;
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    string infix = s.prefixToInfix(prefix);
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << infix << endl;

    return 0;
}