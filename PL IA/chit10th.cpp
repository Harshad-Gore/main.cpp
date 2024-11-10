#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char c) : data(c), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void insertRear(char c) {
        Node* newNode = new Node(c);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    char deleteFront() {
        if (isEmpty()) {
            throw runtime_error("Deque is empty");
        }
        Node* temp = front;
        char data = temp->data;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    char deleteRear() {
        if (isEmpty()) {
            throw runtime_error("Deque is empty");
        }
        Node* temp = rear;
        char data = temp->data;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        return data;
    }
};

bool isPalindrome(const string& str) {
    Deque deque;
    for (char c : str) {
        deque.insertRear(c);
    }

    while (!deque.isEmpty()) {
        if (deque.deleteFront() != deque.deleteRear()) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}