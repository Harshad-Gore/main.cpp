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
        next = nullptr;
    }
};

class Polynomial
{
private:
    Node *head;

public:
    Polynomial()
    {
        head = nullptr;
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
            if (temp)
            {
                cout << " + ";
            }
        }
        cout << endl;
    }

    Polynomial add(Polynomial &p)
    {
        Polynomial result;
        Node *p1 = head;
        Node *p2 = p.head;

        while (p1 && p2)
        {
            if (p1->exponent == p2->exponent)
            {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->exponent > p2->exponent)
            {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            }
            else
            {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }

        while (p1)
        {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }

        while (p2)
        {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }
};

int main()
{
    Polynomial p1, p2, result;

    p1.insertTerm(3, 2);
    p1.insertTerm(5, 1);
    p1.insertTerm(6, 0);

    p2.insertTerm(6, 1);
    p2.insertTerm(8, 0);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    result = p1.add(p2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}