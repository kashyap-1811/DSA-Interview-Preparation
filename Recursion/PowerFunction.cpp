#include <iostream>

using namespace std;

int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        if(n/2==1)
            return x*x;

        return power(x,n/2)*power(x,n/2);
    }
    else
    {
        return x*power(x,n/2)*power(x,n/2);
    }
}

int main()
{
    cout<<"Enter the Value of base: ";
    int a;cin>>a;

    cout<<"Enter the Value of power: ";
    int b;cin>>b;

    cout<<"Ans to "<<a<<" to the power "<<b<<" is: "<<power(a,b);
    return 0;
}