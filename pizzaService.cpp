/*insert delete display update*/
#include <iostream>
using namespace std;
class node
{
public:
    int PizzaID;
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
    void cancelOrder();
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
        cin >> temp->PizzaID;
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
        cout << "Pizza: " << temp->PizzaID << endl;
        cout << "Quantity: " << temp->qyt << endl;
        cout << "Price: " << temp->pizzaPrice << endl;
        cout << "Toppings: " << temp->toppings << endl;
        cout << "Crust: " << temp->pizzaType << endl;
        temp = temp->next;
    } while (temp != head);
}
void orderPizza::cancelOrder()
{
    int id;
    cout << "Enter the Order ID you want to cancel:" << endl;
    cin >> id;
    node *temp = head;
    node *p;
    if (temp->PizzaID == id)
    {
        if (head->next == head)
        {
            p = head;
            head = NULL;
            p->next = NULL;
            delete (p);
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = head->next;
            p = head;
            head = head->next;
            p->next = NULL;
            delete (p);
        }
    }
    else
    {
        cout << "No order found:" << endl;
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
            if (temp->PizzaID == id)
            {
                cout << "Order found:" << endl;
                cout << "Pizza: " << temp->PizzaID << endl;
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
            if (temp->PizzaID == id)
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
    pizza.takeOrder();
    pizza.cancelOrder();
    pizza.searchOrder();
    pizza.showOrder();
    return 0;
}