#include <bits/stdc++.h>

using namespace std;

void permutation(string str , string ans)
{
    if(str.size()==0)
    {
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<str.size();i++)
    {
        char ch=str[i];
        permutation( str.substr(0,i)  + str.substr(i+1,str.size()-1-i) , ans + ch);
    }
}

int main()
{
    string str = "abc";
    permutation(str," ");
    return 0;
}