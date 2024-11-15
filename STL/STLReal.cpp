#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
    string name;
    int age;
    float gpa;

    Student(string n, int a, float g) : name(n), age(a), gpa(g) {}
};

bool compareGPA(Student a, Student b)
{
    return a.gpa > b.gpa;
}

int main()
{
    vector<Student> students;

    students.push_back(Student("Harsahd", 20, 3.5));
    students.push_back(Student("Uber", 22, 3.8));
    students.push_back(Student("Abhinav", 19, 3.2));
    students.push_back(Student("Chetanraje", 21, 3.9));

    cout << "Students before sorting by GPA:" << endl;
    for (auto &student : students)
    {
        cout << student.name << " " << student.age << " " << student.gpa << endl;
    }

    sort(students.begin(), students.end(), compareGPA);

    cout << "\nStudents after sorting by GPA:" << endl;
    for (auto &student : students)
    {
        cout << student.name << " " << student.age << " " << student.gpa << endl;
    }

    return 0;
}