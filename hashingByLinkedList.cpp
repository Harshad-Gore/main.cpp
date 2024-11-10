#include <iostream>
using namespace std;
#define SIZE 20
class node
{
public:
    int marks;
    int rollno;
    string name;
    node *next;
    node()
    {
        marks = 0;
        rollno = 0;
        name = "";
        next = NULL;
    }
};
class HashingTable
{
public:
    node *table[SIZE];
    HashingTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = new node();
            table[i] = NULL;
        }
    }
    void insert(int rollno, string name, int marks)
    {
        int index = rollno % SIZE;
        node *temp = new node();
        temp->rollno = rollno;
        temp->name = name;
        temp->marks = marks;
        if(table[index] == NULL)
        {
            table[index] = temp;
        }
        else
        {
            node *t = table[index];
            while(t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            node *temp = table[i];
            cout << i << " ";
            while (temp != NULL)
            {
                cout << "Roll No: " << temp->rollno << " Name: " << temp->name << " Marks: " << temp->marks << " ";
                temp = temp->next;
            }


            cout << endl;
        }
    }
    void search(int rollno)
    {
        int index = rollno % SIZE;
        node *temp = table[index];
        while (temp != NULL)
        {
            if (temp->rollno == rollno)
            {
                cout << "Roll No: " << temp->rollno << " Name: " << temp->name << " Marks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Record not found" << endl;
    }
};

int main()
{
    HashingTable ht;
    ht.insert(1, "A", 90);
    ht.insert(2, "B", 80);
    ht.insert(3, "C", 70);
    ht.insert(4, "D", 60);
    cout << "Hash Table" << endl;
    ht.display();
    ht.search(1);
    return 0;
}