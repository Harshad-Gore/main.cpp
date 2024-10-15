#include <iostream>

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    friend void printWidth(Box box);
};

void printWidth(Box box) {
    std::cout << "Width of box: " << box.width << std::endl;
}

int main() {
    Box box(10.0);
    printWidth(box);
    return 0;
}
