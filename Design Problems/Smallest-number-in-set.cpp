// leet - 2236
// https://leetcode.com/problems/smallest-number-in-infinite-set/
 
#include <bits/stdc++.h>
using namespace std;
 
class SmallestInfiniteSet {
public:
    int current;
    set<int> s;

    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        
        if(s.size()==0 || current < *s.begin()){
            current++;
            return current - 1;
        }else if(current == *s.begin()){
            current++;
            s.erase({current - 1});
            return current - 1;
        }else{
            int val = *s.begin();
            s.erase({val});
            return val;
        }
    }
    
    void addBack(int num) {
        s.insert({num});
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */