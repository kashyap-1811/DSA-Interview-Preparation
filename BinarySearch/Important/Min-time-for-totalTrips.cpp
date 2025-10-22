// leet - 2187
// https://leetcode.com/problems/minimum-time-to-complete-trips/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 1LL * *min_element(time.begin(), time.end()) * totalTrips;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long trips = 0;
            for (auto t : time) {
                trips += mid / t;
                if (trips >= totalTrips) break; // avoid overflow
            }

            if (trips >= totalTrips) {
                ans = mid;         // possible answer
                right = mid - 1;   // try smaller time
            } else {
                left = mid + 1;    // need more time
            }
        }

        return ans;
    }
};
