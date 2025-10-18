#include <iostream>

using namespace std;

int ModifiedBinarySearch(int *arr, int si ,int ei,int key)
{
    if(si>ei)
        return -1;

    int mid= si + (ei-si)/2;

    if(arr[mid]==key)
    {       
        return mid;
    }  
    else if (arr[si]<=arr[mid])
    {
        if(arr[si]<=key && key<arr[mid])
        {
            return ModifiedBinarySearch(arr,si,mid-1,key);  //left
        }
        else
        {
            return ModifiedBinarySearch(arr,mid+1,ei,key);  //right
        }
    }
    else
    {
        if(arr[ei]>=key && key>arr[mid])
        {
            return ModifiedBinarySearch(arr,mid+1,ei,key);
        }
        else
        {
            return ModifiedBinarySearch(arr,si,mid-1,key);
        }
    }
    
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

    int key;
    cout<<"Enter which element to be searched: ";
    cin>>key;

    cout<<"Index of Key is: "<<ModifiedBinarySearch(arr,0,size-1,key);
    return 0;
}