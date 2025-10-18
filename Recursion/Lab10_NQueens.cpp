#include <bits/stdc++.h>
using namespace std;

bool isSafe(int k, int i, vector<int>&sol)
{
    for(int j=0; j<k; j++)
    {
        if(sol[j] == i || abs(k-j) == abs(i-sol[j]))
            return false;
    }
    return true;
}

void NQueens(int n, vector<int>&sol, int k)
{
    for(int i=0; i<n; i++)
    {
        if(isSafe(k, i, sol))
        {
            sol[k] = i;
            if(k == n-1)
            {
                for(int j=0; j<n; j++)
                    cout<<sol[j]<<" ";
                cout<<endl;
            }
            else
            {
                NQueens(n, sol, k+1);
            }
        }
    }
}

int main()
{
    int n = 10;
    vector<int>sol(n, 0);
    NQueens(n, sol, 0);
    return 0;
}