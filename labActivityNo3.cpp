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
        // cin.ignore();
        // getline(cin, temp->name);
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
    // cin.ignore();
    // getline(cin, temp->name);
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
    // cin.ignore();
    // getline(cin, temp->name);
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
void sll::sort()
{
    node *p = head;
}
int main()
{
    sll so;
    char ch;
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
        case 9:
            so.sort();
        case 10:
            cout << "Exiting.." << endl;
        default:
            cout << "Enter valid choice." << endl;
            break;
        }
    } while (choice != 10);

    return 0;
}
/*
{  node *temp, *p;
    char ch;
  do
  {     temp = new node;
         cout<<“Enter data”;
         cin>>temp->val;  temp->next = NULL; temp->prev = NULL;
         if( head == NULL)
          head = temp;
         else
          {    p =head;
                while ( p->next != NULL)
                     p = p->next ;
             p->next = temp;
            temp->prev = p;
         }
  cout<<“\nDo you want to add more nodes (y/n)”;
 cin>>ch;
while(ch == ‘y’);
*/