#include <iostream>
#include <vector>
using namespace std;

class BloomFilter {
private:
    vector<bool> bits;
    int size;
    int numHashes;

    unsigned int hash1(const string& key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % size;
        }
        return hash % size;
    }

    unsigned int hash2(const string& key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = (hash * 17 + c) % size;
        }
        return hash % size;
    }

    unsigned int hash3(const string& key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = (hash * 7 + c) % size;
        }
        return hash % size;
    }

public:
    BloomFilter(int size, int numHashes) : size(size), numHashes(numHashes) {
        bits.resize(size, false);
    }

    void add(const string& key) {
        bits[hash1(key)] = true;
        bits[hash2(key)] = true;
        bits[hash3(key)] = true;
    }

    bool contains(const string& key) {
        return bits[hash1(key)] && bits[hash2(key)] && bits[hash3(key)];
    }
};

int main() {
    BloomFilter bf(100, 3);
    bf.add("sachin");
    bf.add("kunal");
    bf.add("gaurav");

    cout << "Contains 'kunal': " << (bf.contains("kunal") ? "Yes" : "No") << endl;
    cout << "Contains 'kalpesh': " << (bf.contains("kalpesh") ? "Yes" : "No") << endl;

    return 0;
}