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

    int srow=0,scol=0;
    int erow=row-1,ecol=col-1;

    cout<<endl;

    while(srow<=erow&&scol<=ecol)
    {
        //top
        for(int i=scol;i<=ecol;i++)
        {
            cout<<arr[srow][i]<<"  ";
        }

        //right
        for(int i=srow+1;i<=erow;i++)
        {
            cout<<arr[i][ecol]<<"  ";
        }

        //bottom
        for(int i=ecol-1;i>=scol;i--)
        {
            if(srow==erow)
                break;

            cout<<arr[erow][i]<<"  ";
        }

        //left
        for(int i=erow-1;i>srow;i--)
        {
            if(scol==ecol)
                break;
            cout<<arr[i][scol]<<"  ";
        }

        srow++;scol++;
        erow--;ecol--;
    }
    return 0;
}