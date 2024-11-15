#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

struct Student
{
    string name;
    int grade;
};

void addStudent(vector<Student> &students, const string &name, int grade)
{
    students.push_back({name, grade});
}

void displayStudents(const vector<Student> &students)
{
    for (const auto &student : students)
    {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

double calculateAverageGrade(const vector<Student> &students)
{
    if (students.empty())
        return 0.0;
    int total = accumulate(students.begin(), students.end(), 0,
                           [](int sum, const Student &s)
                           { return sum + s.grade; });
    return static_cast<double>(total) / students.size();
}

int main()
{
    vector<Student> students;

    addStudent(students, "Abc", 85);
    addStudent(students, "Bcd", 90);
    addStudent(students, "Cde", 78);

    cout << "Students List:" << endl;
    displayStudents(students);

    double averageGrade = calculateAverageGrade(students);
    cout << "Average Grade: " << averageGrade << endl;

    return 0;
}