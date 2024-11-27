#include <iostream>
#include <cmath>
#define MAX 20
using namespace std;

class Stack
{
public:
  string arr[MAX];
  int top;
  Stack()
  {
    top = -1;
  }

  bool isEmpty();
  bool isFull();
  void push(string str);
  string pop();
  int precedence(char x);
};

bool Stack::isEmpty()
{
  return top == -1;
}

bool Stack::isFull()
{
  return top == MAX - 1;
}

void Stack::push(string str)
{
  if (isFull())
  {
    cout << "\nStack is full.\n";
  }
  else
  {
    top++;
    arr[top] = str;
  }
}

string Stack::pop()
{
  if (isEmpty())
  {
    cout << "\nStack is empty.\n";
    return "";
  }
  else
  {
    string temp = arr[top];
    top--;
    return temp;
  }
}

int Stack::precedence(char x)
{
  if (x == '+' || x == '-')
  {
    return 1;
  }
  else if (x == '*' || x == '/')
  {
    return 2;
  }
  else if (x == '^')
  {
    return 3;
  }
  else
  {
    return 0;
  }
}

class Expression
{
public:
  void prefixToInfix();
  void infixToPostfix();
  void postfixEval();
  int operation(int x, int y, char op)
  {
    switch (op)
    {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    case '^':
      return pow(x, y);
    default:
      return 0;
    }
  }

  bool isOperator(char x)
  {
    return (x == '+' || x == '-' || x == '*' || x == '/');
  }

  bool isOperand(char x)
  {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
  }
};

void Expression::prefixToInfix()
{
  Stack s;
  string prefix, infix;
  cout << "--------------------------------------------------" << endl;
  cout << "Enter the prefix expression: ";
  cin >> prefix;
  int length = prefix.length();

  for (int i = length - 1; i >= 0; i--)
  {
    if (isOperand(prefix[i]))
    {
      s.push(string(1, prefix[i]));
    }
    else if (isOperator(prefix[i]))
    {
      string op1 = s.pop();
      string op2 = s.pop();
      string temp = "(" + op1 + prefix[i] + op2 + ")";
      s.push(temp);
    }
  }

  infix = s.pop();
  cout << "\nInfix expression is: " << infix << endl;
}

void Expression::infixToPostfix()
{
  Stack s;
  string infix, postfix;
  cout << "--------------------------------------------------" << endl;
  cout << "Enter the infix expression: ";
  cin >> infix;
  int length = infix.length();

  for (int i = 0; i < length; i++)
  {
    if (infix[i] == ' ')
    {
      continue; // Skip spaces
    }
    if (isOperand(infix[i]))
    {
      postfix += infix[i];
    }
    else if (infix[i] == '(')
    {
      s.push(string(1, infix[i]));
    }
    else if (infix[i] == ')')
    {
      while (!s.isEmpty() && s.arr[s.top][0] != '(')
      {
        postfix += s.pop();
      }
      s.pop(); // Pop '('
    }
    else if (isOperator(infix[i]))
    {
      if (s.isEmpty())
      {
        s.push(string(1, infix[i]));
      }
      else
      {
        if (s.precedence(infix[i]) == s.precedence(s.arr[s.top][0]) && infix[i] == '^')
        {
          s.push(string(1, infix[i])); // Right associative for '^'
        }
        else
        {
          while (!s.isEmpty() && s.precedence(infix[i]) <= s.precedence(s.arr[s.top][0]))
          {
            postfix += s.pop();
          }
          s.push(string(1, infix[i]));
        }
      }
    }
  }

  while (!s.isEmpty())
  {
    postfix += s.pop();
  }

  cout << "\nPostfix expression is: " << postfix << endl;
}

class Stack1
{
public:
  int top;
  int arr[MAX];
  Stack1()
  {
    top = -1;
  }
  void push(int x);
  int pop();
};

void Stack1::push(int x)
{
  if (top == MAX - 1)
  {
    cout << "\nStack is full.\n";
  }
  else
  {
    top++;
    arr[top] = x;
  }
}

int Stack1::pop()
{
  if (top == -1)
  {
    cout << "\nStack is empty.\n";
    return -1;
  }
  else
  {
    int temp = arr[top];
    top--;
    return temp;
  }
}

void Expression::postfixEval()
{
  Stack1 s;
  string postfix;
  cout << "......." << endl;
  cout << "Enter the postfix expression: ";
  getline(cin >> ws, postfix);
  int len = postfix.length();

  for (int i = 0; i < len; i++)
  {
    if (postfix[i] == ' ')
    {
      continue;
    }
    else if (isdigit(postfix[i]))
    {
      int num = 0;
      while (isdigit(postfix[i]))
      {
        num = num * 10 + (postfix[i] - '0');
        i++;
      }
      s.push(num);
      i--;
    }
    else if (isOperator(postfix[i]))
    {
      int op2 = s.pop();
      int op1 = s.pop();
      int result = operation(op1, op2, postfix[i]);
      s.push(result);
    }
  }
  int final_r = s.pop();
  cout << "\nResult of postfix evaluation: " << final_r << endl;
}

int main()
{
  Expression exp;
  int choice;
  do
  {
    cout << "........" << endl;
    cout << "Expression Using Stack" << endl;
    cout << "1. Prefix to Infix " << endl;
    cout << "2. Infix to Postfix " << endl;
    cout << "3. Postfix Evaluation " << endl;
    cout << "4. Exit " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      exp.prefixToInfix();
      break;
    case 2:
      exp.infixToPostfix();
      break;
    case 3:
      exp.postfixEval();
      break;
    case 4:
      cout << "Exiting the program..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }

  } while (choice != 4);
  return 0;
}