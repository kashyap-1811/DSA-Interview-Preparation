#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of lines: ";
    cin>>n;

    //upper-half
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }

        for(int sp=1;sp<=2*(n-i);sp++)
        {
            cout<<" ";
        }
        
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    //Lower-half
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i+1);j++)
        {
            cout<<"*";
        }

        for(int sp=2*n-2;sp>2*(n-i);sp--)
        {
            cout<<" ";
        }

        for(int j=1;j<=(n-i+1);j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}