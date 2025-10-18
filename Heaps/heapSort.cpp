#include <bits/stdc++.h>

using namespace std;

/*
    for ascending order --> max heap
    for descending order -->min heap

    for making CBT a heap
    call heapify for all nodes except last level
    last level nodes are from n/2 to n

    call heapify for 0 to (n/2 - 1)
*/

void heapify(int i, vector<int>&arr, int n)
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left<n && arr[left]<arr[maxI])
        maxI = left;
    if(right<n && arr[right]<arr[maxI])
        maxI = right;

    if(maxI != i){
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n);
    }  //maxI is the left or right index whichever be the greater
}

void HeapSort(vector<int>&arr)
{
    int n = arr.size();

    //step 1: creating maxHeap
    for(int i=n/2-1; i>=0; i--)
        heapify(i, arr, n);

    //step 2: taking elements to their respective places
    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(0, arr, i); //heapitfy(0, arr, i) => here i represents that each time loop runs the size of arr 
                            // needed for sorting are decreasing 
    }
}

int main()
{
    vector<int>arr = {1, 4, 2, 5, 3};
    HeapSort(arr);
    for(auto i : arr)
        cout<<i<<" ";

    return 0;
}