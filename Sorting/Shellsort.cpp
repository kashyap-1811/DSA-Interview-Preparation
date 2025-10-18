// C++ implementation of Shell Sort
#include  <iostream>
using namespace std;

void Shell(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];  // Temporarily store arr[i]
            int j;
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];  // Move element up by the gap
            }
            arr[j] = temp;
        }
    }
}


void printArray(const int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {9, 7, 1 , 10, 13, 90, 0 ,1, -2, 6}, i;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    Shell(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}
