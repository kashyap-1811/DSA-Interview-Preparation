#include <bits/stdc++.h>

using namespace std;

void printSubString(string str , string subset)
{
    if(str.size()==0)
    {
        if(!subset[0])
        {
            cout<<"\\0"<<" ";
            return;
        }
        cout<<subset<<" ";
        return;
    }

    char ch = str[0];

    printSubString(str.substr(1 , str.size()-1) , subset); //NO
    printSubString(str.substr(1 , str.size()-1) , subset+ch); //YES
}

int main()
{
    string str = "abc";
    printSubString(str , "");
    return 0;
}