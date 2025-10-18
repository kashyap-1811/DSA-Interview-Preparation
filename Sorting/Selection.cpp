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

    //Selection Sort
    
    for(int i=0;i<size;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        swap(arr[i],arr[min]);


        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";

        cout<<endl;
    }

    cout<<"Array after Sorting: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}