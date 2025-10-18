#include <iostream>
#include<vector>
using namespace std;

void Merge(int *arr, int si ,int ei)
{
    vector<int>temp;
    int mid = si+(ei-si)/2;
    int i=si;
    int j=mid+1;

    while(i<=mid&&j<=ei)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[j++]);
        }
        else
        {
            temp.push_back(arr[i++]);
        }
    }

    while(i<=mid)
        temp.push_back(arr[i++]);

    while(j<=ei)
        temp.push_back(arr[j++]);

    //copying to arr
    for(int idx=si,x=0;idx<=ei;idx++)
    {
        arr[idx]=temp.at(x++);
    }
}

void MergeReverse(int *arr,int si ,int ei)
{
    if(si>=ei)
        return;

    int mid= si + (ei-si)/2;

    MergeReverse(arr,si,mid-1);  //Left half
    MergeReverse(arr,mid+1,ei);  //right

    Merge(arr,si,ei);
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

    MergeReverse(arr,0,size-1);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}