#include <bits/stdc++.h>
using namespace std;

int power(int x, int pow){
    if(pow == 0)
        return 1;
    if(pow == 1)
        return x;
    if(pow % 2 == 0){
        int t = power(x, pow/2);
        return t * t; 
    }
    else{
        int t = power(x, (pow-1)/2);
        return x * t * t;
    }
}

int nthRoot(int n, int m){
    int st = 0, end = m;

    while(st <= end){
        int mid = (st + end) / 2;
        int ans = power(mid, n);

        if(ans == m)
            return mid;
        
        if(ans < m)
            st = mid + 1;
        else    
            end = mid - 1;
    }

    return -1;
}
 
int main()
{
    int n = 5;
    int m = 32;

    cout << nthRoot(n, m) << endl;
    return 0;
}