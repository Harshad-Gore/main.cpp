#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    if(t>=1 && t<=1000){
    while(t--){
        int a,b;
        cin>>a>>b;
      if((a >= 0 && a <= 10000)&&(b >= 0 && b <= 10000)){
          cout<<"\n"<<a+b;
      }else{
          cout<<"Invalid Input";
      }
    }
 }
	return 0;
}
