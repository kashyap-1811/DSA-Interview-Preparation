// leet - 3296
// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool time_needed(int mountainHeight, vector<int>& workerTimes,
                     long long mid) {
        long long heightCutInTimeMid = 0;

        for (int i : workerTimes) {
            double a = 1, b = 1, c = -2 * (mid / i);

            double D = b * b - 4 * a * c;

            if (D < 0) {
                // cout << "No real root\n";
                return 0;
            }

            double root1 = (-b + sqrt(D)) / (2 * a);
            double root2 = (-b - sqrt(D)) / (2 * a);

            long long positiveIntRoot = max(floor(root2), floor(root1));
            heightCutInTimeMid += positiveIntRoot;
        }

        // cout << mid << " " << heightCutInTimeMid << endl;
        return heightCutInTimeMid >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes =
            *max_element(workerTimes.begin(), workerTimes.end());
        long long low = 1, high = static_cast<long long>(maxWorkerTimes) *
                             mountainHeight * (mountainHeight + 1) / 2;
        long long mid = low + (high - low) / 2;
        long long ans = 5000050000000000;

        while (low <= high) {
            mid = low + (high - low) / 2;

            // cout << low << " " << high << ": ";
            bool check = time_needed(mountainHeight, workerTimes, mid);

            if (check) {// can be done in mid time
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};