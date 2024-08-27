//** ideal calc **
#include <iostream>
using namespace std;

class Calculator {
public:
    int a, b, c;

    void read() {
        cout << "Enter the first integer: ";
        cin >> a;
        cout << "Enter the second integer: ";
        cin >> b;
    }

    void displayMenu() {
        cout << "\nChoose an operation:\n";
        cout << "1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n";
    }

    void performOperation(int choice) {
        switch (choice) {
            case 1:
                c = a + b;
                cout << "Result: " << c;
                break;
            case 2:
                c = a - b;
                cout << "Result: " << c;
                break;
            case 3:
                if (b != 0) {
                    c = a / b;
                    cout << "Result: " << c;
                } else {
                    cout << "Error: Division by zero is not allowed.";
                }
                break;
            case 4:
                c = a * b;
                cout << "Result: " << c;
                break;
            default:
                cout << "Invalid choice. Please select 1 to 4.";
        }
    }

    void run() {
        char repeat;
        do {
            read();
            displayMenu();
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            performOperation(choice);
            cout << "\nDo you want to perform another calculation? (Y/N): ";
            cin >> repeat;
        } while (repeat == 'Y' || repeat == 'y');
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}
