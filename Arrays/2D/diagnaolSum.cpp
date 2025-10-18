#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"Enter the order of the Matrix: ";
    cin>>size;
    int arr[size][size];
    int sum=0;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<"Enter the element at index: ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }
    
        for(int j=0;j<size;j++)
        {
            sum+=arr[j][j];
            sum+=arr[j][size-j-1];
        }

    if(size%2==1)
    {
        sum-=arr[size/2][size/2];
    }

    cout<<"Diagonals sum is: "<<sum;
    return 0;
}