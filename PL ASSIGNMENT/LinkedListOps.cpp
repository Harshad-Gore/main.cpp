#include <iostream>
using namespace std;

class node
{
public:
    string name;
    int prn;
    float cgpa;
    node *next;
    node()
    {
        next = NULL;
    }
};

class sll
{
    node *head;

public:
    sll()
    {
        head = NULL;
    }
    void create();
    void display();
    void insertBegin();
    void append();
    void insertAfter();
    void delNode();
    void search();
    void update();
    void sort();
};

void sll::create()
{
    node *temp, *p;
    char ch;
    do
    {
        temp = new node();
        cout << "Enter Name of Student:\n";
        cin >> temp->name;
        cout << "Enter PRN:\n";
        cin >> temp->prn;
        cout << "Enter CGPA:\n";
        cin >> temp->cgpa;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        cout << "Do you want to add more nodes (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void sll::display()
{
    node *p = head;
    while (p != NULL)
    {
        cout << "Name: " << p->name << endl;
        cout << "PRN: " << p->prn << endl;
        cout << "CGPA: " << p->cgpa << endl;
        p = p->next;
    }
}

void sll::insertBegin()
{
    node *temp;
    temp = new node();
    cout << "Enter Name of Student:\n";
    cin >> temp->name;
    cout << "Enter PRN:\n";
    cin >> temp->prn;
    cout << "Enter CGPA:\n";
    cin >> temp->cgpa;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void sll::append()
{
    node *temp = new node();
    node *p;

    cout << "Enter Name of Student:\n";
    cin >> temp->name;
    cout << "Enter PRN:\n";
    cin >> temp->prn;
    cout << "Enter CGPA:\n";
    cin >> temp->cgpa;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void sll::insertAfter()
{
    int prn_search;
    cout << "Enter PRN after which to insert:\n";
    cin >> prn_search;

    node *temp = new node();
    cout << "Enter Name of Student:\n";
    cin >> temp->name;
    cout << "Enter PRN:\n";
    cin >> temp->prn;
    cout << "Enter CGPA:\n";
    cin >> temp->cgpa;

    node *p = head;
    while (p != NULL && p->prn != prn_search)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        temp->next = p->next;
        p->next = temp;
    }
    else
    {
        cout << "PRN not found.\n";
    }
}

void sll::delNode()
{
    int prn_del;
    cout << "Enter PRN of node to delete:\n";
    cin >> prn_del;

    node *p = head, *prev = NULL;
    while (p != NULL && p->prn != prn_del)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "PRN not found.\n";
        return;
    }
    if (prev == NULL)
    {
        head = p->next;
    }
    else
    {
        prev->next = p->next;
    }
    delete p;
}

void sll::search()
{
    int prn_search;
    cout << "Enter PRN to search:\n";
    cin >> prn_search;

    node *p = head;
    while (p != NULL)
    {
        if (p->prn == prn_search)
        {
            cout << "Found: " << p->name << ", CGPA: " << p->cgpa << endl;
            return;
        }
        p = p->next;
    }
    cout << "PRN not found.\n";
}

void sll::update()
{
    int prn_update;
    cout << "Enter PRN to update:\n";
    cin >> prn_update;

    node *p = head;
    while (p != NULL)
    {
        if (p->prn == prn_update)
        {
            cout << "Enter new Name:\n";
            cin >> p->name;
            cout << "Enter new CGPA:\n";
            cin >> p->cgpa;
            return;
        }
        p = p->next;
    }
    cout << "PRN not found.\n";
}

void sll::sort()
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->prn > q->prn)
            {
                string tempName = p->name;
                p->name = q->name;
                q->name = tempName;

                int tempPrn = p->prn;
                p->prn = q->prn;
                q->prn = tempPrn;

                float tempCgpa = p->cgpa;
                p->cgpa = q->cgpa;
                q->cgpa = tempCgpa;
            }
        }
    }
}

int main()
{
    sll so;
    int choice;
    do
    {
        cout << "\nMenu.\n";
        cout << "1. Create linked list." << endl;
        cout << "2. Display List." << endl;
        cout << "3. Insert at beginning." << endl;
        cout << "4. Insert at end." << endl;
        cout << "5. Insert at location." << endl;
        cout << "6. Delete." << endl;
        cout << "7. Search." << endl;
        cout << "8. Update." << endl;
        cout << "9. Sort." << endl;
        cout << "10. Exit." << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            so.create();
            break;
        case 2:
            so.display();
            break;
        case 3:
            so.insertBegin();
            break;
        case 4:
            so.append();
            break;
        case 5:
            so.insertAfter();
            break;
        case 6:
            so.delNode();
            break;
        case 7:
            so.search();
            break;
        case 8:
            so.update();
            break;
        case 9:
            so.sort();
            break;
        case 10:
            cout << "Exiting..\n";
            break;
        default:
            cout << "Enter valid choice.\n";
            break;
        }
    } while (choice != 10);

    return 0;
}
