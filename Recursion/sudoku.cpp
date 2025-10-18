#include <bits/stdc++.h>

using namespace std;

void printSudoku(int arr[9][9])
{
    for(int i=0;i<9;i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "---------------------" << endl;
        }
        for(int j=0;j<9;j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int arr[9][9], int row, int col,int digit){
    
    //Vertical and horizontal check
    for(int i=0;i<9;i++)
    {
        if(arr[row][i]==digit)
            return false;

        if(arr[i][col]==digit)
            return false;
    }

    //3X3 check
    int SR=(row/3)*3;
    int SC=(col/3)*3;

    for(int i=SR;i<=SR+2;i++)
    {
        for(int j=SC;j<=SC+2;j++)
        {
            if(arr[i][j]==digit)
                return false;
        }
    }

    return true;
}

bool updateSudoku(int arr[9][9],int row,int col)
{
    if(row == 9)
    {
        printSudoku(arr);
        return true;
    }

    int nextRow=row;
    int nextCol=col+1;
    if(col+1 == 9)
    {
        nextRow=row+1;
        nextCol=0;
    }

    if(arr[row][col]!=0)
    {
        return updateSudoku(arr,nextRow,nextCol);
    }

    for(int digit=1;digit<=9;digit++)
    {
        if(isSafe(arr,row,col,digit))
        {
            arr[row][col]=digit;
            if(updateSudoku(arr,nextRow,nextCol))
            {
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int arr[9][9]={
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(updateSudoku(arr,0,0))
    {
        cout<<"Sudoku is Solved!!! ";
    }
    else
    {
        cout<<"NO ans is possible!!! ";
    }

    return 0;
}