#include <iostream>
using namespace std;
#define SIZE 10
class HashTable
{
public:
    int hashTable[SIZE];
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            hashTable[i] = -1;
        }
    }
    int hashFunction(int key)
    {
        return key % SIZE;
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
        }
        else if (index == SIZE - 1)
        {
            index = 0;
            while (hashTable[index] != -1)
            {
                index++;
            }
            hashTable[index] = key;
        }
        else
        {
            while (hashTable[index] != -1)
            {
                index++;
            }
            hashTable[index] = key;
        }
    }
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : " << hashTable[i] << endl;
        }
    }
    void search(int key)
    {
        int index = hashFunction(key);
        if (hashTable[index] == key)
        {
            cout << "Key found at index " << index << endl;
        }
        else
        {
            while (hashTable[index] != key)
            {
                index++;
            }
            cout << "Key found at index " << index << endl;
        }
    }
};
int main()
{
    string key;
    HashTable ht;
    cout << "Enter key: ";
    cin >> key;
    for (int i = 0; i < key.length(); i++)
    {
        ht.insert(key[i]);
    }
    ht.display();
    ht.search('a');
    return 0;
}