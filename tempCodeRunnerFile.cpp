#include <iostream>
using namespace std;

class Abstract {
public:
    virtual void show() = 0;
};

class Derived : public Abstract {
public:
    void show() {
        cout << "Derived implementation" << endl;
    }
};

int main() {
    Abstract *a = new Derived();
    a->show();
    delete a;
    return 0;
}
