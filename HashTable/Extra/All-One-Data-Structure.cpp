// leet - 432
// https://leetcode.com/problems/all-oone-data-structure/
 
#include <bits/stdc++.h>
using namespace std;
 
class AllOne {
public:
    map<string, int> m;
    map<int, set<string>> forMinMax;

    AllOne() {}
    
    void inc(string key) {
        m[key]++;
        
        if (m[key] > 1) {
            forMinMax[m[key] - 1].erase(key);
            if (forMinMax[m[key] - 1].empty())
                forMinMax.erase(m[key] - 1);
        }
        
        forMinMax[m[key]].insert(key);
    }
    
    void dec(string key) {
        m[key]--;
        
        forMinMax[m[key] + 1].erase(key);
        if (forMinMax[m[key] + 1].empty())
            forMinMax.erase(m[key] + 1);

        if (m[key] == 0) {
            m.erase(key);
        } else {
            forMinMax[m[key]].insert(key);
        }
    }
    
    string getMaxKey() {
        if (forMinMax.empty())
            return "";
        auto last = prev(forMinMax.end());
        auto &s = last->second;
        return *s.begin();
    }
    
    string getMinKey() {
        if (forMinMax.empty())
            return "";
        auto first = forMinMax.begin();
        auto &s = first->second;
        return *s.begin();
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */