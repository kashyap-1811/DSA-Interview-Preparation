#include <iostream>

using namespace std;

int partition(int arr[],int si,int ei)
{
    int j = ei;
    int i = ei+1;

    for(; j>si; j--)
    {
        if(arr[j] > arr[si])
            swap(arr[--i], arr[j]);
    }

    swap(arr[--i], arr[si]);
    return i;
}

void print(int *arr , int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void QuickSort(int arr[],int si, int ei, int size)
{

    if(si>=ei)
        return;
    
    int pivotIdx = partition(arr,si,ei);

    print(arr, size);

    QuickSort(arr, si ,pivotIdx-1, size);  //Left Half
    QuickSort(arr, pivotIdx+1, ei, size); //Right Half
}

int main()
{
    int size;
    cout<<"Enter Size of the element: ";
    cin>>size;

    int arr[size];

    cout<<"Enter the elements of the Array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    QuickSort(arr,0,size-1, size);

    // for(int i=0;i<size;i++)
    //     cout<<arr[i]<<" ";
    return 0;
}