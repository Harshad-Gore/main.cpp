#include <iostream>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;
    Node(int coeff, int exp)
    {
        coefficient = coeff;
        exponent = exp;
        next = NULL;
    }
};

class Polynomial
{
private:
    Node *head;

public:
    Polynomial()
    {
        head = NULL;
    }

    void insertTerm(int coeff, int exp)
    {
        Node *newNode = new Node(coeff, exp);
        if (!head || head->exponent < exp)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next && temp->next->exponent >= exp)
            {
                temp = temp->next;
            }
            if (temp->exponent == exp)
            {
                temp->coefficient += coeff;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp->coefficient > 0) 
            {
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Polynomial poly;
    poly.insertTerm(3, 2);
    poly.insertTerm(-5, 1);
    poly.insertTerm(6, 0);
    poly.insertTerm(4, 3);

    cout << "Polynomial Equation: ";
    poly.display();

    return 0;
}