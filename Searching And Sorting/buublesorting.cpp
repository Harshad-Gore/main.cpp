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
class QuickSort
{
    public:
    student arr[size];
    int partition(int low, int high)
    {
        int pivot = arr[high].marks;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j].marks > pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void Quick()
    {
        quickSort(0, size - 1);
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