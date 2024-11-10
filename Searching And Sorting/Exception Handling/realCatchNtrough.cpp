#include <iostream>
using namespace std;

class bookList
{
public:
    string bookName;
    int bookId;
    bookList()
    {
        cout << "Enter the name of the book." << endl;
        cin >> bookName;
        cout << "Enter the id." << endl;
        cin >> bookId;
    }
};
int main()
{

    int days;
    bookList book;
    cout << "Number of days you borrowed the book." << endl;
    cin >> days;
    try
    {
        if (days < 0)
        {
            cout << "Days cannot be negative." << endl;
        }
        else if (days > 15)
        {
            throw days;
        }
        else
        {
            cout << "Book is returned on time. No fine." << endl;
        }
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    catch (int days)
    {
        cout << "You have to pay a fine of " << (days - 15) * 2 << " rupees." << endl;
    }
    catch (...)
    {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}