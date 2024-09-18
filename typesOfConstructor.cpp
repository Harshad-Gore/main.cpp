#include <iostream>
using namespace std;

class Harshad {
    string urName;
    string carName;
    int price;
    int bYear;

public:
    Harshad() {
        urName = "Unknown";
        carName = "Unknown";
        price = 0;
        bYear = 0;
    }

    Harshad(string name, string car, int p, int year) {
        urName = name;
        carName = car;
        price = p;
        bYear = year;
    }

    Harshad(const Harshad &obj) {
        urName = obj.urName;
        carName = obj.carName;
        price = obj.price;
        bYear = obj.bYear;
    }

    void display() {
        cout << "Your Name: " << urName << endl;
        cout << "Car Name: " << carName << endl;
        cout << "Price of the Car: $" << price << endl;
        cout << "Model Year: " << bYear << endl;
    }
};

int main() {
    Harshad car1;
    car1.display();

    string name, car;
    int price, year;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter car name: ";
    cin >> car;
    cout << "Enter price of the car: ";
    cin >> price;
    cout << "Enter model year: ";
    cin >> year;

    Harshad car2(name, car, price, year);
    car2.display();

    Harshad car3 = car2;
    car3.display();

    return 0;
}