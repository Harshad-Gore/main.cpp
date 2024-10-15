#include<iostream>
using namespace std;
class MyClass{
    public:
    int g,k;
    float r;
    void myFuction(){
        cout<<"enter value of g,k and r: ";
        cin>>g>>k>>r;
        cout<<"g : "<<g<<"\nk : "<<k<<"\nr : ";
        cout<<"some content in parent class";
    }
};

class MyOtherClass{
    public:
    void myotherclass(){
        cout<<"some content in another class ";
    }
};

class MyChildClass:
public MyClass, public MyOtherClass{

};

int main(){
    MyChildClass Myob;
    Myob.myFuction();
    Myob.myotherclass();
    return 0;
}