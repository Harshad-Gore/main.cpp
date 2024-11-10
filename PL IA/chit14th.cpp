#include <iostream>

using namespace std;

class HashTable {
private:
    int table[9];
    bool occupied[9];
public:
    HashTable() {
        for (int i = 0; i < 9; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int key) {
        int index = key % 9;
        while (occupied[index]) {
            index = (index + 1) % 9;
        }
        table[index] = key;
        occupied[index] = true;
    }

    void display() {
        for (int i = 0; i < 9; i++) {
            if (occupied[i]) {
                cout << i << ": " << table[i] << "\n";
            } else {
                cout << i << ": NULL\n";
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int data[] = {10, 5, 4, 14, 15, 20, 11, 1, 6, 16, 36, 28};
    for (int i = 0; i < 12; i++) {
        hashTable.insert(data[i]);
    }
    hashTable.display();
    return 0;
}
