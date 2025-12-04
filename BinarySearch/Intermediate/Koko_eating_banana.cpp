// leet - 875
// https://leetcode.com/problems/koko-eating-bananas/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    // Helper function to calculate total hours Koko needs at a given speed
    long long timeTaken(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {
            // Use ceiling division: each pile takes ceil(pile/speed) hours
            hours += ceil((double)piles[i] / speed);
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;                          // Minimum possible speed
        int high = *max_element(piles.begin(), piles.end());  // Maximum possible speed
        int ans = high;                       // Store minimum valid speed

        // Binary search over speed range
        while (low <= high) {
            int mid = low + (high - low) / 2; // Safe mid calculation
            long long hrs = timeTaken(piles, mid);

            if (hrs <= h) {
                // Koko can finish within h hours -> try slower (smaller) speed
                ans = mid;
                high = mid - 1;
            } else {
                // Koko needs more hours -> increase speed
                low = mid + 1;
            }
        }

        return ans;
    }
};