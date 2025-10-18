#include <iostream>

using namespace std;

int tilling(int col)
{

    if(col==0||col==1)
        return 1;

    // //vertical
    // int ans1=tilling(col-1);

    // //horizontal
    // int ans2=tilling(col-2);

    return tilling(col-1)+tilling(col-2);
}

int main()
{
    int n;
    cout<<"Enter the Amount of col: ";
    cin>>n;

    cout<<"No of ways to  arrange the tiles are: "<<tilling(n);
    return 0;
}