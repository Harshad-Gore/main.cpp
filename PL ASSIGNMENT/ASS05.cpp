#include <iostream>
using namespace std;
class node
{
public:
    int PizzaName;
    int pizzaPrice;
    string pizzaType;
    string toppings;
    int qyt;
    node *next;
    node()
    {
        next = NULL;
    }
};
class orderPizza
{
    node *head;

public:
    orderPizza()
    {
        head = NULL;
    }
    void takeOrder();
    void showOrder();
    void deliverOrder();
    void updateOrder();
    void searchOrder();
};
void orderPizza::takeOrder()
{
    char ch;
    do
    {
        node *temp = new node();
        cout << "Enter Order ID:\n";
        cin >> temp->PizzaName;
        cout << "Enter quantity of the pizza:" << endl;
        cin >> temp->qyt;
        cout << "Enter Pizza Price:\n";
        cin >> temp->pizzaPrice;
        cout << "Which toppings you want on your Pizza:\n";
        cin >> temp->toppings;
        cout << "What kind of crust do you want:\n";
        cin >> temp->pizzaType;

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
        }
        cout << "Do you want to add more Pizzas(Y/n)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
void orderPizza::showOrder()
{
    node *temp = head;
    do
    {
        cout << "Pizza: " << temp->PizzaName << endl;
        cout << "Quantity: " << temp->qyt << endl;
        cout << "Price: " << temp->pizzaPrice << endl;
        cout << "Toppings: " << temp->toppings << endl;
        cout << "Crust: " << temp->pizzaType << endl;
        temp = temp->next;
    } while (temp != head);
}
void orderPizza::deliverOrder()
{
    if (head == NULL)
    {
        cout << "No orders to deliver!\n";
        return;
    }
    node *temp = head;
    if (head->next == head)
    {
        head = NULL;
        delete temp;
        cout << "Delivered the order successfully!\n";
    }
    else
    {
        node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
        temp->next = NULL;
        delete temp;
        cout << "Delivered the order successfully!\n";
    }
}
void orderPizza::searchOrder()
{
    int id;
    cout << "Enter your order ID to search your order:" << endl;
    cin >> id;
    node *temp = head;
    int flag = 0;
    if (head != NULL)
    {
        do
        {
            if (temp->PizzaName == id)
            {
                cout << "Order found:" << endl;
                cout << "Pizza: " << temp->PizzaName << endl;
                cout << "Quantity: " << temp->qyt << endl;
                cout << "Price: " << temp->pizzaPrice << endl;
                cout << "Toppings: " << temp->toppings << endl;
                cout << "Crust: " << temp->pizzaType << endl;
                flag = 1;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    if (flag == 0)
    {
        cout << "Order ID not found." << endl;
    }
}
void orderPizza::updateOrder()
{
    int id;
    cout << "Enter your order ID:" << endl;
    cin >> id;
    node *temp = head;
    int flag = 0;
    if (head != NULL)
    {
        do
        {
            if (temp->PizzaName == id)
            {
                cout << "Order found....." << endl;
                cout << "Enter new quantity of the pizza:" << endl;
                cin >> temp->qyt;
                cout << "Enter new Pizza Price:" << endl;
                cin >> temp->pizzaPrice;
                cout << "Enter new toppings you want on your Pizza:" << endl;
                cin >> temp->toppings;
                cout << "Enter new kind of crust you want:" << endl;
                cin >> temp->pizzaType;
                flag = 1;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    if (flag == 0)
    {
        cout << "Order ID not found." << endl;
    }
}
int main()
{
    orderPizza pizza;
    int choice;
    do
    {
        cout << "\n--- Pizza Service Menu ---\n";
        cout << "1. Take Order\n";
        cout << "2. Show Orders\n";
        cout << "3. Deliver Order\n";
        cout << "4. Update Order\n";
        cout << "5. Search Order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pizza.takeOrder();
            break;
        case 2:
            pizza.showOrder();
            break;
        case 3:
            pizza.deliverOrder();
            break;
        case 4:
            pizza.updateOrder();
            break;
        case 5:
            pizza.searchOrder();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}