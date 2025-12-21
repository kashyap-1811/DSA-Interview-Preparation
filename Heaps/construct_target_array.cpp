// leet - 
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long currSum = 0;

        for(int i : target){
            currSum += i;
            pq.push(i);
        }

        while(!pq.empty()){ 
            long long top = pq.top();
            pq.pop();

            if(top == 1)
                return true;

            currSum -= top;
            if(top < currSum || currSum == 0)
                return false;

            top = top % currSum;
            if(top == 0){
                if(currSum == 1)
                    top = 1;
                else return false;
            }
            
            currSum += top;
            if(top > 1)
                pq.push(top);
        }

        return true;
    }
};