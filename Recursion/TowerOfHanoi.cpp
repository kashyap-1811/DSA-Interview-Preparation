#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n, char source, char auxillary, char destination)
{
    if(n==1)
    {
        cout<<"transfer "<<n<<" from "<<source<<" to "<<destination<<endl;
        return;
    }

    Hanoi(n-1, source, destination, auxillary);
    cout<<"transfer "<<n<<" from "<<source<<" to "<<destination<<endl;
    Hanoi(n-1, auxillary,source,destination);
}

int main()
{
    int n=3;  //No of disk
    Hanoi(n,'A','B','C');  //A->source  B->auxillary  C->destination
    return 0;
}