#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortAscending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortDescending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {60, 20, 40, 70, 30, 10};
    int arr2[] = {60, 20, 40, 70, 30, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original array:\n";
    printArray(arr1, n);
    heapSortAscending(arr1, n);
    cout << "Ascending Order (Max Heap):\n";
    printArray(arr1, n);
    heapSortDescending(arr2, n);
    cout << "Descending Order (Min Heap):\n";
    printArray(arr2, n);
    return 0;
}