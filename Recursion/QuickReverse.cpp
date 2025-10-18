#include <iostream>

using namespace std;

int partition(int *arr, int si , int ei)
{
    int i=si-1;
    int j=si;

    for(; j<ei;j++)
    {
        if(arr[j]>=arr[ei])
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }

    i++;
    swap(arr[i],arr[ei]);  
    return i;  //returning pivot Index
}

void QuickReverse(int arr[], int si, int ei)
{
    if(si>=ei)
        return;

    int pivot = partition(arr,si,ei);

    QuickReverse(arr, si, pivot-1);
    QuickReverse(arr, pivot+1,ei);
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

    QuickReverse(arr,0,size-1);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}