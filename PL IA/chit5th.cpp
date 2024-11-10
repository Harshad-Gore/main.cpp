#include <iostream>
using namespace std;

class Node
{
public:
    int seatNumber;
    string passengerName;
    Node *next;

    Node(int seat, string name)
    {
        seatNumber = seat;
        passengerName = name;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    void bookTicket(int seat, string name)
    {
        Node *newNode = new Node(seat, name);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Ticket booked successfully for " << name << " at seat number " << seat << "." << endl;
    }

    void cancelTicket(int seat)
    {
        if (head == NULL)
        {
            cout << "No reservations to cancel." << endl;
            return;
        }

        Node *temp = head, *prev = NULL;
        do
        {
            if (temp->seatNumber == seat)
            {
                if (temp == head)
                {
                    if (head->next == head)
                    {
                        head = NULL;
                    }
                    else
                    {
                        Node *last = head;
                        while (last->next != head)
                        {
                            last = last->next;
                        }
                        head = head->next;
                        last->next = head;
                    }
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Ticket for seat number " << seat << " canceled successfully." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "No reservation found for seat number " << seat << "." << endl;
    }

    void displayReservations()
    {
        if (head == NULL)
        {
            cout << "No reservations found." << endl;
            return;
        }
        Node *temp = head;
        cout << "Current Reservations:" << endl;
        do
        {
            cout << "Seat Number: " << temp->seatNumber << ", Passenger: " << temp->passengerName << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularLinkedList reservationSystem;
    int choice, seat;
    string name;

    do
    {
        cout << "\nRailway Reservation System\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Display Reservations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter seat number: ";
            cin >> seat;
            cout << "Enter passenger name: ";
            getline(cin, name);
            reservationSystem.bookTicket(seat, name);
            break;
        case 2:
            cout << "Enter seat number to cancel: ";
            cin >> seat;
            reservationSystem.cancelTicket(seat);
            break;
        case 3:
            reservationSystem.displayReservations();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
