#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    inline void setWidth(double w) {
        this->width = w;
    }

    friend void printWidth(Box box);

    friend class BoxManager;

    static void displayMessage() {
        cout << "This is a static member function." << endl;
    }
};

void printWidth(Box box) {
    cout << "Width of box: " << box.width << endl;
}

class BoxManager {
public:
    void displayBoxWidth(Box& box) {
        cout << "Box width from BoxManager: " << box.width << endl;
    }
};

int main() {
    Box box(10.0);
    printWidth(box);

    box.setWidth(20.0);
    printWidth(box);

    Box::displayMessage();

    BoxManager manager;
    manager.displayBoxWidth(box);

    return 0;
}