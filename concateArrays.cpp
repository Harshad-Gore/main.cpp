#include<iostream>
#include<string>
using namespace std;

int main() {
    int n1, n2;
    
    cout << "Enter the size of the first array: ";
    cin >> n1;
    
    cout << "Enter the size of the second array: ";
    cin >> n2;
    
    int num1[n1], num2[n2];
    string name1[n1], name2[n2];
    
    cout << "Enter elements for the first number array: ";
    for (int i = 0; i < n1; i++) {
        cin >> num1[i];
    }
    
    cout << "Enter elements for the second number array: ";
    for (int i = 0; i < n2; i++) {
        cin >> num2[i];
    }
    
    cout << "Enter elements for the first string array: ";
    for (int i = 0; i < n1; i++) {
        cin >> name1[i];
    }
    
    cout << "Enter elements for the second string array: ";
    for (int i = 0; i < n2; i++) {
        cin >> name2[i];
    }
    
    int numResult[n1 + n2];
    for (int i = 0; i < n1; i++) {
        numResult[i] = num1[i];
    }
    for (int i = 0; i < n2; i++) {
        numResult[n1 + i] = num2[i];
    }
    
    string nameResult[n1 + n2];
    for (int i = 0; i < n1; i++) {
        nameResult[i] = name1[i];
    }
    for (int i = 0; i < n2; i++) {
        nameResult[n1 + i] = name2[i];
    }
    
    cout << "Concatenated number array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << numResult[i] << " ";
    }
    cout << endl;
    
    cout << "Concatenated string array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << nameResult[i] << " ";
    }
    cout << endl;
    
    return 0;
}
