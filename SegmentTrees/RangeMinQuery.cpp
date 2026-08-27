// https://www.geeksforgeeks.org/problems/range-minimum-query/1

class Solution {
  public:
    vector<int> tree;
    
    int create(int idx, int st, int end, vector<int> &arr) {
        if (st == end)
            return tree[idx] = arr[st];
        
        int mid = (st + end) / 2;
        int left = create(2 * idx + 1, st, mid, arr);
        int right = create(2 * idx + 2, mid + 1, end, arr);
        
        return tree[idx] = min(left, right);
    }
    
    int findMin(int idx, int si, int sj, int qi, int qj) {
        // no overlapping
        if (sj < qi || qj < si)
            return INT_MAX;
        
        // full overlapping
        if (si >= qi && sj <= qj)
            return tree[idx];
        
        // half overlapping
        int mid = (si + sj) / 2;
        int left = findMin(2 * idx + 1, si, mid, qi, qj);
        int right = findMin(2 * idx + 2, mid + 1, sj, qi, qj);
        return min(left, right);
    }
    
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        tree.resize(4 * n);
        for (int i = 0; i < 4 * n; i++)
            tree[i] = INT_MAX;
        
        // create segment tree
        create(0, 0, n - 1, arr);
        
        // queries
        vector<int> ans;
        for (auto q : queries) 
            ans.push_back(findMin(0, 0, n - 1, q[0], q[1]));
            
        return ans;
    }
};