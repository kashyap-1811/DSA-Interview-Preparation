#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>&arr, int si, int mid, int ei)
{
    vector<int>temp;
    int i=si;
    int j=mid+1;

    while(i<=mid && j<=ei)
    {
        if(arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else   
            temp.push_back(arr[j++]);
    }

    while(i<=mid)
        temp.push_back(arr[i++]);
    while (j<=ei)
    {
        /* code */
        temp.push_back(arr[j++]);
    }
    
    for(int k=si,x=0; k<=ei; k++)
        arr[k] = temp[x++];
}

void mergeSort(vector<int>&arr, int si, int ei)
{
    if(si == ei)  return;
    int mid = (si + ei)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, mid, ei);
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    vector<int>arr;

    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    mergeSort(arr,0 ,arr.size()-1);
    return 0;
}