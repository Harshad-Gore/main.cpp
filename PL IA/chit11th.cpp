#include <iostream>

using namespace std;

struct Friend {
    string name;
    string phone;
};

void sortFriends(Friend friends[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (friends[j].name > friends[j + 1].name) {
                Friend temp = friends[j];
                friends[j] = friends[j + 1];
                friends[j + 1] = temp;
            }
        }
    }
}

void sentinelSearch(Friend friends[], int &n, const string &key) {
    friends[n].name = key;
    int i = 0;
    while (friends[i].name != key) {
        ++i;
    }
    if (i < n) {
        cout << "Found: " << friends[i].name << " - " << friends[i].phone << "\n";
    } else {
        cout << "Not found. Adding to phonebook.\n";
        string phone;
        cout << "Enter phone number: ";
        cin >> phone;
        friends[n].name = key;
        friends[n].phone = phone;
        n++;
        sortFriends(friends, n);
    }
}

int main() {
    Friend friends[100] = {{"Alice", "12345"}, {"Bob", "67890"}, {"Charlie", "13579"}};
    int n = 3;
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;
    sentinelSearch(friends, n, searchName);
    return 0;
}
