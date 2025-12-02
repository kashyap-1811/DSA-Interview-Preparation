// leet - 81
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If mid points to the target
            if (arr[mid] == k)
                return true;

            // Edge case: all three are equal, we cannot determine which side is sorted
            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }

            // If the left half is sorted
            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= k && k <= arr[mid])
                {
                    high = mid - 1; // Target lies in left
                }
                else
                {
                    low = mid + 1; // Target lies in right
                }
            }
            else
            {
                // Right half is sorted
                if (arr[mid] <= k && k <= arr[high])
                {
                    low = mid + 1; // Target lies in right
                }
                else
                {
                    high = mid - 1; // Target lies in left
                }
            }
        }

        return false;
    }
};