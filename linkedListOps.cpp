#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int rollNumber;
    Student *next;
};

int main()
{
    Student *head = NULL;
    Student *head2 = NULL;
    int choice, rollNumber, position;
    string name;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert student at beginning\n";
        cout << "2. Insert student at end\n";
        cout << "3. Insert student after a specific position\n";
        cout << "4. Delete student at a specific position\n";
        cout << "5. Display all students\n";
        cout << "6. Reverse the list\n";
        cout << "7. Concatenate two lists\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNumber;

            // Insert at Beginning
            {
                Student *newStudent = new Student();
                newStudent->name = name;
                newStudent->rollNumber = rollNumber;
                newStudent->next = head;
                head = newStudent;
            }
            break;

        case 2:
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNumber;

            // Insert at End
            {
                Student *newStudent = new Student();
                newStudent->name = name;
                newStudent->rollNumber = rollNumber;
                newStudent->next = NULL;

                if (head == NULL)
                {
                    head = newStudent;
                }
                else
                {
                    Student *last = head;
                    while (last->next != NULL)
                        last = last->next;
                    last->next = newStudent;
                }
            }
            break;

        case 3:
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNumber;
            cout << "Enter position to insert after (0-indexed): ";
            cin >> position;

            // Insert after a specific position
            {
                Student *temp = head;
                for (int i = 0; i < position; i++)
                {
                    if (temp != NULL)
                        temp = temp->next;
                }

                if (temp == NULL)
                {
                    cout << "Position out of bounds." << endl;
                }
                else
                {
                    Student *newStudent = new Student();
                    newStudent->name = name;
                    newStudent->rollNumber = rollNumber;
                    newStudent->next = temp->next;
                    temp->next = newStudent;
                }
            }
            break;

        case 4:
            cout << "Enter position to delete (0-indexed): ";
            cin >> position;

            // Delete at a specific position
            {
                if (head == NULL)
                {
                    cout << "List is empty." << endl;
                }
                else if (position == 0)
                {
                    Student *temp = head;
                    head = head->next;
                    delete temp;
                }
                else
                {
                    Student *temp = head;
                    for (int i = 0; temp != NULL && i < position - 1; i++)
                        temp = temp->next;

                    if (temp == NULL || temp->next == NULL)
                    {
                        cout << "Position out of bounds." << endl;
                    }
                    else
                    {
                        Student *next = temp->next->next;
                        delete temp->next;
                        temp->next = next;
                    }
                }
            }
            break;

        case 5:
            // Display all students
            {
                Student *temp = head;
                while (temp != NULL)
                {
                    cout << "Name: " << temp->name << "\nRoll Number: " << temp->rollNumber << endl;
                    temp = temp->next;
                }
            }
            break;

        case 6:
            // Reverse the list
            {
                Student *prev = NULL;
                Student *current = head;
                Student *next = NULL;

                while (current != NULL)
                {
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }
                head = prev;
            }
            break;

        case 7:
            // Concatenate two lists
            cout << "Enter elements for the second list (enter -1 to stop):\n";
            while (true)
            {
                cout << "Enter student name (or -1 to stop): ";
                cin.ignore();
                getline(cin, name);
                if (name == "-1")
                    break;
                cout << "Enter roll number: ";
                cin >> rollNumber;

                Student *newStudent = new Student();
                newStudent->name = name;
                newStudent->rollNumber = rollNumber;
                newStudent->next = NULL;

                if (head2 == NULL)
                {
                    head2 = newStudent;
                }
                else
                {
                    Student *last = head2;
                    while (last->next != NULL)
                        last = last->next;
                    last->next = newStudent;
                }
            }

            if (head == NULL)
            {
                head = head2;
            }
            else
            {
                Student *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = head2;
            }
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 8);

    return 0;
}