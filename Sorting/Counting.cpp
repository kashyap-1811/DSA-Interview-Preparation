#include <bits/stdc++.h>

using namespace std;

void countSort(int *arr, int size)
{
    int M = 0;
    for(int i=0; i<size; i++)
        M = max(arr[i], M);

    vector<int> count(M+1, 0);

    for(int i=0; i<size; i++)
        count[arr[i]]++;

    for(int i=0; i<M; i++)
    {
        count[i+1] += count[i];
    }

    vector<int>output(size, 0);

    for(int i=size-1; i>=0; i--)
    {
        int index = count[arr[i]]--;
        index--;

        output[index] = arr[i];
    }

    for(int i=0; i<size; i++)
        cout<<output[i]<<" ";
}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter the elements of the array: "<<endl;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    //Counting Sort
    countSort(arr, size);

    // cout<<"Array after Sorting: ";
    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}