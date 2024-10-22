#include <bits/stdc++.h>
using namespace std;
#define size 3

class student
{
public:
    string name;
    int marks;
    int rollno;
    string department;
    float cgpa;
    void insert()
    {
        cout << "Enter The details of the student." << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Marks: ";
        cin >> marks;
        cout << "Roll No: ";
        cin >> rollno;
        cout << "Department: ";
        cin >> department;
        cout << "CGPA: ";
        cin >> cgpa;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Department: " << department << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};
class bubbleSort
{
public:
    student arr[size];
    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j].marks < arr[j + 1].marks)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};
int main()
{
    bubbleSort bubble;
    for (int i = 0; i < size; i++)
    {
        bubble.arr[i].insert();
    }
    bubble.sort();
    for (int i = 0; i < size; i++)
    {
        bubble.arr[i].display();
    }
    return 0;
}