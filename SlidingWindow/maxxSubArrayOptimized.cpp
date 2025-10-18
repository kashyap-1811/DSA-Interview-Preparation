//Kadane's Method
#include <iostream>

using namespace std;

int max_sum(int *p,int n)
{
    int max=INT32_MIN,count=0;
    for(int start=0;start<n;start++)
    {
        count+=p[start];
        if(count>max)
            max=count;
        if(count<0)
            count=0;
    }
    return max;
}

int main()
{
    int size;
    cout<<"Enter Size of the element: ";
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element: ";
        cin>>arr[i];
    }

    int max=max_sum(arr,size);
    cout<<endl<<"Max sum of SubArray is: "<<max;
    return 0;
}