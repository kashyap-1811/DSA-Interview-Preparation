#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;

    while(t){
        int n;
        cin >> n;
        vector<int> arr(n);

        int oddCount = 0, evenCount = 0;

        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0)
                evenCount++;
            else    
                oddCount++;
        }

        if(oddCount && evenCount)
            sort(arr.begin(), arr.end());

        for(int i : arr)
            cout << i << " ";
        cout << endl << endl;

        t -= 1;
    }
    return 0;
}