#include <iostream>

using namespace std;

int main()
{
    int row,col;
    cout<<"Enter no. of rows: ";
    cin>>row;
    cout<<"Enter no. of column: ";
    cin>>col;

    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"Enter the element at index: ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }

    cout<<endl<<"Enter element to be searched: ";
    int key;cin>>key;

    //top right
    int r=0,c=col-1;
    int cell;

    while(r<row&&c>=0)
    {
        cell=arr[r][c];
        if(cell==key)
        {
            cout<<"Index of Element is: ["<<r<<"]["<<c<<"]";
            break;
        }
        else if(cell>key)
        {
           c--;
        }
        else
        {
            r++;
        }
    }

    if(r==row||c<0)
    {
        cout<<"Entered element do not exist in array.";
    }

    return 0;
}