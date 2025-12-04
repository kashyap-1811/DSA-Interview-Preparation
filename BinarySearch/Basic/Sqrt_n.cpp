#include <bits/stdc++.h>
using namespace std;
 
int sqrt(int n){
    int st = 0, end = n;
    int ans = 0;

    while(st <= end){
        int mid = (st + end) / 2;

        if(mid * mid <= n){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 36;
    cout << sqrt(n);
    return 0;
}