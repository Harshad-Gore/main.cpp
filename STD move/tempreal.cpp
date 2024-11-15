#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Container
{
public:
    void add(const T &item)
    {
        items.push_back(item);
    }

    void remove(const T &item)
    {
        items.erase(remove(items.begin(), items.end(), item), items.end());
    }

    void display() const
    {
        for (const auto &item : items)
        {
            cout << item << " ";
        }
        cout << endl;
    }

private:
    vector<T> items;
};

int main()
{
    Container<int> intContainer;
    intContainer.add(1);
    intContainer.add(2);
    intContainer.add(3);
    cout << "Int Container: ";
    intContainer.display();

    intContainer.remove(2);
    cout << "Int Container after removing 2: ";
    intContainer.display();

    Container<string> stringContainer;
    stringContainer.add("apple");
    stringContainer.add("banana");
    stringContainer.add("cherry");
    cout << "String Container: ";
    stringContainer.display();

    stringContainer.remove("banana");
    cout << "String Container after removing banana: ";
    stringContainer.display();

    return 0;
}