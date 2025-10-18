#include <bits/stdc++.h>

using namespace std;

int ways(int n, int m, int i, int j)
{
    if(i==n-1 && j==m-1)
    {
        return 1;
    }

    int v1=0,v2=0;
    if(j != m-1)
         v1 = ways(n,m,i,j+1);

    if(i != n-1)
         v2 = ways(n,m,i+1,j);

    return v1+v2;
}

int main()
{
    int n=4;
    int m=4;

    int count = ways(n,m,0,0);
    cout<<"No of ways are: "<<count;
    return 0;
}
