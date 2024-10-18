#include <iostream>
using namespace std;

class DemoClass
{
    public:
    int Demofun(int i)
    {
        return i;
    }
    double Demofun(double d)
    {
        return d;
    }
};
int main() {
    
    DemoClass obj;
    cout << obj.Demofun(5) << endl;
    cout << obj.Demofun(555.5) << endl;
    return 0;
}