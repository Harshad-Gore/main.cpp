#include <iostream>

using namespace std;

void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    float *L = new float[n1];
    float *R = new float[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    float percentages[] = {72.5, 85.3, 91.2, 68.4, 77.5, 89.9, 93.4};
    int n = sizeof(percentages) / sizeof(percentages[0]);
    mergeSort(percentages, 0, n - 1);
    cout << "Sorted percentages: ";
    for (int i = 0; i < n; i++) cout << percentages[i] << " ";
    return 0;
}
