#include <iostream>
using namespace std;

class A
{
    public:
    void display()
    {
        cout << "Display of A" << endl;
    }
};
class B: public A
{
    public:
    void display()
    {
        cout << "Display of B" << endl;
    }
};
int main() {
    
    A obj;
    obj.display();
    B obj2;
    obj2.display();
    return 0;
}