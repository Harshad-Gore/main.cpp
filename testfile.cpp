#include <iostream>
using namespace std;

class Instrument {
public:
    virtual void play() = 0;
};

class Piano : public Instrument {
public:
    void play() {
        cout << "Playing Piano" << endl;
    }
};

int main() {
    Instrument *inst = new Piano();
    inst->play();
    delete inst;
    return 0;
}
