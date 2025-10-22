// Cses - 1071
// https://cses.fi/problemset/task/1071/
 
#include <bits/stdc++.h>
using namespace std;
 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t){
        // row = x and column = y
        long long x, y; 
        cin >> x >> y;

        long long cell = max(x, y) - 1; 
        cell *= cell;

        if(cell % 2 == 0){
            if(max(x, y) == x)
                cell += y;
            else    
                cell += (y + y - x);
        }else{
            if(max(x, y) == y)
                cell += x;
            else
                cell += (x + x - y);
        }
        
        cout << cell << endl;
        
        t--;
    }
    
    return 0;
}

/*
    Easy Solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y;
        cin >> x >> y;

        long long n = max(x, y);
        long long base = (n - 1) * (n - 1);
        long long ans = 0;

        if (n % 2 == 1) {
            // odd layer -> goes downward
            if (x == n)
                ans = base + y;
            else
                ans = n * n - (x - 1);
        } else {
            // even layer -> goes rightward
            if (y == n)
                ans = base + x;
            else
                ans = n * n - (y - 1);
        }

        cout << ans << "\n";
    }

    return 0;
}
*/