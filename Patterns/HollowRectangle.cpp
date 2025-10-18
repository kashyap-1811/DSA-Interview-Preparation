#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of lines: ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cout<<"*";

            for(int j=2;j<n;j++)
            {
                if(i==1||i==n)
                    cout<<"*";
                else
                    cout<<" ";
            }

            cout<<"*";
        cout<<endl;
    }
    return 0;
}