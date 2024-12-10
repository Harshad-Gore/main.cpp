#include <iostream>
using namespace std;

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the element occurring odd number of times
int findOddOccurrence(int arr[], int n)
{
    // Sort the array
    bubbleSort(arr, n);

    // Traverse the sorted array to count occurrences
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        // If the current element is the same as the previous one, increment the count
        if (i < n && arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            // If count is odd, return the element
            if (count % 2 != 0)
            {
                return arr[i - 1];
            }
            // Reset count for the next group
            count = 1;
        }
    }

    // If no odd occurrence is found (this shouldn't happen as per the problem statement)
    return -1;
}

int main()
{
    // Example array (test case)
    int arr[] = {1, 2, 3, 2, 3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int oddOccurringNumber = findOddOccurrence(arr, n);

    // Output the result
    cout << "The number occurring odd number of times is: " << oddOccurringNumber << endl;

    return 0;
}
