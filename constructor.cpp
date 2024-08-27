#include <iostream>
using namespace std;

class harshad
{
public:
    string urName;
    int price;
    string carName;
    int bYear;

    void takeInput()
    {
        cout << "Enter your name:";
        cin >> urName;
        cout << "Enter name of your car:";
        cin >> carName;
        cout << "Price of the car:";
        cin >> price;
        cout << "Enter model year of the car:";
        cin >> bYear;
    }
    void display()
    {
        
    }
};
int main()
{
    harshad harsh;
    harsh.takeInput();
    return 0;
}