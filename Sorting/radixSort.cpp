#include <bits/stdc++.h>

using namespace std;

int getMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) // Start from index 1
        if (max < arr[i])
            max = arr[i];
    return max;
}

void countSort(int *arr, int n, int exp)
{
    int output[n], count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Compute prefix sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / exp) % 10]] = arr[i]; // Decrement after usage
    }

    // Copy output array back to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int *arr, int n)
{
    int m = getMax(arr, n); // Find the maximum number

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: " << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Radix Sort
    radixSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
