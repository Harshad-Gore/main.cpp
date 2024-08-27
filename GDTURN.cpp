#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
         cin>>x>>y;
        if((x>=1 && x<=6) && (y>=1 && y<=6)){
            if((x+y)>6){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n" ;
            }
        }
      }
	return 0;
}
