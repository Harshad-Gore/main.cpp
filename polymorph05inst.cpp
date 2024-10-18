#include <iostream>
using namespace std;

class Food {
    public:
    virtual void display() {
        cout << "This is a regular food item." << endl;
    }
};

class SpecialFood : public Food {
    public:
    void display()
    {
        cout << "This is a special food item with a chef's recipe!" << endl;
    }
};

class Order {
    public:
    int placeOrder(int itemCount) {
        cout << "Ordered " << itemCount << " regular items." << endl;
        return itemCount;
    }

    double placeOrder(double totalAmount) {
        cout << "Total bill amount: ₹" << totalAmount << endl;
        return totalAmount;
    }
};

int main() {
    Food regularFood;
    SpecialFood specialFood;

    regularFood.display();
    specialFood.display();

    Order order;
    order.placeOrder(3);
    order.placeOrder(750.50);

    return 0;
}
