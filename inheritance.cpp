#include <iostream>
using namespace std;

// base class
class Employee
{
public:
    int id;
};

// derived class
class programmer : public Employee
{
public:
    int bonus;
    int salary;
    void setSalary(int s)
    {
        salary = s;
    }
    int getSalary()
    {
        return salary;
    }
};

int main()
{
    programmer p1;
    int p, t;
    p1.setSalary(50000);
    p1.bonus = 15000;
    cout << "Salary: " << p1.getSalary() << endl;
    cout << "Bonus: " << p1.bonus << endl;
    cout << "enter value of p&t: ";
    cin >> p >> t;
    p1.setSalary(p);
    p1.bonus = t;
    cout << "Updated Salary: " << p1.getSalary() << endl;
    cout << "Updated Bonus: " << p1.bonus << endl;
    return 0;
}