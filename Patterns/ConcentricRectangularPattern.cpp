#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cout << " Enter n: ";
    cin >> n;

    int r = n - 1; // rows

    for(int i = 0; i <= 2 * r; i++) {
        int k; // 0 to n-1
        if(i < n) 
            k = i % n;
        else    
            k = n - 2 - i % n;

        int val = n;

        // decrease phase
        for(int j = 0; j < r; j++) {
            cout << val << " ";
            if(j < k)
                val--;
        }
        
        // increase phase
        for(int j = r; j > 0; j--) {
            if(j < k)
                val++;
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}