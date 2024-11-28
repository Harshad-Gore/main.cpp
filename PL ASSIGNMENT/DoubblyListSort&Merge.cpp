#include <iostream>
using namespace std;

class node
{
public:
    int rollNo;
    int marks;
    node *next;
    node *prev;

    node(){
        next = prev = NULL;
    }
};

class marklist
{
public:
    node *head;

    marklist()  {
    head =NULL;
    }

    ~marklist()
    {
        node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void create();
    void print();
    void bubbleSort();
    int countNodes();
    node *swap(node *ptr1, node *ptr2);
    marklist merge(marklist &l1, marklist &l2);
};

void marklist::create()
{
    node *temp;
    char ch;
    do
    {
        temp = new node;
        cout << "Enter roll number:" << endl;
        cin >> temp->rollNo;
        cout << "Enter marks:" << endl;
        cin >> temp->marks;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        cout << "Do you want to add more nodes (Y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void marklist::print()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "Roll No: " << temp->rollNo << endl;
        cout << "Marks: " << temp->marks << endl;
        temp = temp->next;
    }
}

int marklist::countNodes()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *marklist::swap(node *p1, node *p2)
{
    if (p2 == NULL) return p1;

    if (p1->prev)
        p1->prev->next = p2;
    if (p2->next)
        p2->next->prev = p1;

    p2->prev = p1->prev;
    p1->next = p2->next;
    p2->next = p1;
    p1->prev = p2;

    return p2;
}

void marklist::bubbleSort()
{
    int n = countNodes();
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; ++i)
    {
        node *current = head;
        bool swapped = false;

        while (current && current->next)
        {
            if (current->marks > current->next->marks)
            {
                node *nextNode = current->next;
                head = (current == head) ? swap(current, nextNode) : head;
                swapped = true;
            }
            else
            {
                current = current->next;
            }
        }

        if (!swapped)
            break;
    }
}

marklist marklist::merge(marklist &l1, marklist &l2)
{
    marklist l3;
    node *p = l1.head;
    node *q = l2.head;
    node *r = NULL;

    while (p != NULL && q != NULL)
    {
        node *temp = new node;
        if (p->marks < q->marks)
        {
            temp->rollNo = p->rollNo;
            temp->marks = p->marks;
            p = p->next;
        }
        else
        {
            temp->rollNo = q->rollNo;
            temp->marks = q->marks;
            q = q->next;
        }

        if (l3.head == NULL)
        {
            l3.head = temp;
            r = l3.head;
        }
        else
        {
            r->next = temp;
            temp->prev = r;
            r = r->next;
        }
    }

    while (p != NULL)
    {
        node *temp = new node;
        temp->rollNo = p->rollNo;
        temp->marks = p->marks;
        r->next = temp;
        temp->prev = r;
        r = r->next;
        p = p->next;
    }

    while (q != NULL)
    {
        node *temp = new node;
        temp->rollNo = q->rollNo;
        temp->marks = q->marks;
        r->next = temp;
        temp->prev = r;
        r = r->next;
        q = q->next;
    }

    return l3;
}

int main()
{
    marklist m1;
    m1.create();
    cout << "\nOriginal List:\n";
    m1.print();

    m1.bubbleSort();
    cout << "\nSorted List:\n";
    m1.print();

    return 0;
}