#include <iostream>
#include<cstdlib>
using namespace std;

int binarySearch(int *ptr, int size,int key)
{
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;

    while(start<=end)
    {
        mid=(start+end)/2;
        if(ptr[mid]==key)
            return mid;
        else if(ptr[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}

int main()
{
    int size;
    cout<<"Please enter the size of the array: ";
    cin>>size;

    int *p= (int*)malloc(size*sizeof(int));

    for(int i=0;i<size;i++)
    {
        cout<<"Enter the value at index: ["<<i<<"]: ";
        cin>>*(p+i);
    }

    //sorting
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(p[j]<p[i])
            {
                int temp=*(p+i);
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    cout<<endl<<"Enter the element to be searched: ";
    int key;cin>>key;

    int index=binarySearch(p,size,key);
    if(index==-1)
    {
        cout<<"Element not found.";
    }
    else
    {
        cout<<endl<<"Index at which element present is: "<<index;
    }
    free(p);
    return 0;
}