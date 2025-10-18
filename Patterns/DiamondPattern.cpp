#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of lines: ";
    cin>>n;


    for(int i=1;i<=n/2;i++)
    {
        for(int sp=1;sp<=n/2-i;sp++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n/2;i>0;i--)
    {
        for(int sp=i;sp<n/2;sp++)
        {
            cout<<" ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}