#include <iostream>
#include<algorithm>
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

    sort(arr,arr+size, greater<int>());

    cout<<"Array after Sorting: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}