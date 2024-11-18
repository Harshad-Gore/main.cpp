// this is the assignment of problem solving which consists of use of contructor
#include <iostream>
using namespace std;

class Harshad
{
    string urName;
    string carName;
    int price;
    int bYear;

public:
    Harshad()
    {
        cout << "Enter your name: ";
        cin >> urName;
        cout << "Enter name of your car: ";
        cin >> carName;
        cout << "Price of the car: ";
        cin >> price;
        cout << "Enter model year of the car: ";
        cin >> bYear;
    }

    void display()
    {
        cout << "\n---- Car Details ----" << endl;
        cout << "Your Name: " << urName << endl;
        cout << "Car Name: " << carName << endl;
        cout << "Price of the Car: $" << price << endl;
        cout << "Model Year: " << bYear << endl;
    }
};

int main()
{
    Harshad harsh;
    harsh.display();
    return 0;
}
