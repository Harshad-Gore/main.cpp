#include <iostream>
using namespace std;
class node
{
public:
    int rollNo;
    int marks;
    node *next;
    node *prev;
    node()
    {
        next = prev = NULL;
    }
};
class marklist
{
public:
    node *head;
    marklist()
    {
        head = NULL;
    }
    int create();
    void print();
    void bubbleSort(int n);
    int countNodes();
    node *swap(node *ptr1, node *ptr2);
    marklist merge(marklist l1, marklist l2);
};
int marklist::create()
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
            head = temp;
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout << "do you want to add more nodes(Y/n)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
void marklist::print()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "Roll No:" << temp->rollNo << endl;
        cout << "Marks:" << temp->marks << endl;
        temp = temp->next;
    }
}
node *marklist::swap(node *p1, node *p2)
{
    if (p1->prev == NULL)
    {
        node *temp = p2->next;
        p2->next = p1;
        p2->prev = NULL;
        p1->prev = p2;
        p1->next = temp;
        temp->prev = p1;
        return p2;
    }
    else if (p2->next == NULL)
    {
        node *temp = p1->prev;
        p2->next = p1;
        p1->next = NULL;
        p2->prev = p2;
        p1->prev = temp;
        temp->next = p2;
        return p2;
    }
    else if (p2->next == NULL)
    {
        node *temp1 = p1->prev;
        node *temp2 = p2->next;
        p2->next = p1;
        p1->prev = p2;
        p2->prev = temp1;
        temp1->next = p2;
        p1->next = temp2;
        temp2->prev = p1;
        return p2;
    }
}
void marklist::bubbleSort(int cnt)
{
    node **h;
    int swapped;
    for (int i = 0; i < cnt; i++)
    {
        h = &(head);
        swapped = 0;
        for(int j =0; j < cnt - i - 1; j++)
        {
            node *p1 = *h;
            node *p2 = p1->next;
            if(p1->marks>p2->marks)
            {
                *h = swap(p1,p2);
                swapped = 1;
            }
            h = &(*h)->next;
            if (swapped == 0)
            {
                break;
            }
        }
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
marklist marklist::merge(marklist l1, marklist l2)
{
    marklist l3;
    node *p,*q,*r;
    if (p->marks> q->marks)
    {
        l3->head;
    }

}

int main()
{
    marklist m1,l1,l2,l3;
    m1.create();
    int cnt = m1.countNodes();
    m1.bubbleSort(cnt);
    m1.print();
    return 0;   
}