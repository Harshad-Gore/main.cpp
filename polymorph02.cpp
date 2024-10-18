#include <iostream>
using namespace std;

class BaseClass
{
    public:
    void display()
    {
        cout << "Display of Base Class" << endl;
    }
};
class DerivedClass : public BaseClass
{
    public:
    void display()
    {
        cout << "Display of Derived Class" << endl;
    }
};
int main() {
    
    DerivedClass obj;
    obj.display();
    return 0;
}