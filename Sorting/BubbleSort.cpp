#include <iostream>

using namespace std;

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

    //Bubble sort
    for(int i=0;i<size;i++)
    {
        bool swaped = false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped = true;
            }
        }

        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;

        if(!swaped)
            break;
    }

    cout<<"Array after Sorting: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}