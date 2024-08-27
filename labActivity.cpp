#include <iostream>
using namespace std;

class Car
{
public:
    string model;
    int year;
    float price;

    void read();
    void display();
};

void Car::read()
{
    cout << "Enter the Model of the car: ";
    cin >> model;
    cout << "Enter the Year of the car: ";
    cin >> year;
    cout << "Enter the Price of the car: ";
    cin >> price;
}

void Car::display()
{
    cout << "\nModel: " << model;
    cout << "\nYear: " << year;
    cout << "\nPrice: " << price;
}

int main()
{
    Car cars[50];
    int ch, n = 0, i, loc, flag = 0;
    do
    {
        cout << "\n1. Accept Details\n2. Display Details\n3. Add new car\n4. Delete car by year\n";
        cout << "5. Search car by year\n6. Update car information\n7. Sort cars by price\n8. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter number of cars: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter details for car " << i + 1 << ": ";
                cars[i].read();
            }
            break;
        case 2:
            for (i = 0; i < n; i++)
            {
                cars[i].display();
            }
            break;
        case 3:
            if (n < 50)
            {
                cout << "Enter the location where you want to add new car (index): ";
                cin >> loc;
                if (loc > n || loc < 0)
                {
                    cout << "Invalid Choice\n";
                }
                else
                {
                    for (i = n - 1; i >= loc - 1; i--)
                    {
                        cars[i + 1] = cars[i];
                    }
                    cars[loc - 1].read();
                    n++;
                }
                break;
            }
            else
            {
                cout << "Cannot add more cars. Array is full.\n";
            }
            break;
        case 4:
            cout << "Enter the year of the car to delete: ";
            cin >> loc;
            for (i = 0; i < n; i++)
            {
                if (cars[i].year == loc)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Please enter a valid Year.";
            }
            else
            {
                for ( ; i < n - 1; i++)
                {
                    cars[i] = cars[i + 1];
                }
                n--;
            }
            break;
        case 5:
            cout << "Enter the year of the car to search: ";
            cin >> loc;
            flag = 0;
            for (i = 0; i < n; i++)
            {
                if (cars[i].year == loc)
                {
                    cars[i].display();
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Car not found.\n";
            }
            break;
        case 6:
            cout << "Enter the year of the car to update: ";
            cin >> loc;
            flag = 0;
            for (i = 0; i < n; i++)
            {
                if (cars[i].year == loc)
                {
                    cout << "Enter new details for car:\n";
                    cars[i].read();
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Car not found.\n";
            }
            break;
        case 7:
            for (i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (cars[i].price < cars[j].price)
                    {
                        Car k = cars[i];
                        cars[i] = cars[j];
                        cars[j] = k;
                    }
                }
            }
            cout << "Cars sorted by price.\n";
            break;
        case 8:
            cout << "Exiting..\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (ch != 8);
    return 0;
}
