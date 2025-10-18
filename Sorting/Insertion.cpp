#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++)
    {
        int j = i-1;
        int curr = arr[i];
        while(j>=0 && arr[j]>curr)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curr;
        
        for(int k=0; k<n; k++)
            cout<<arr[k]<<"  ";
        cout<<endl;
    }
    return 0;
}