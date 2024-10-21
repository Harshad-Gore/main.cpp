//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
bool check_duck(string N);
 
int main(void)
{
    int t; 
    cin>>t;
    while(t--)
    {
        string N; 
        cin>>N; 
  
        if (check_duck(N)) 
            cout << "YES\n"; 
        else
            cout << "NO\n"; 
     
    }
}
// } Driver Code Ends


bool check_duck(string N){
    //code
    int len = N.length();
    // Check if the first character is '0'
    if (N[0] == '0') {
        return false;
    }
    
    // Check for '0' in the rest of the string
    for (int i = 1; i < len; i++) {
        if (N[i] == '0') {
            return true;
        }
    }
    
    return false;
}