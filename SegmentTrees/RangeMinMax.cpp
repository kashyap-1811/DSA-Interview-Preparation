// https://www.geeksforgeeks.org/problems/range-min-max-queries4557/1

class Solution {
  public:
    void print(vector<int> &arr) {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
    
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    vector<int> getMinMaxUtil(int i, int si, int sj, int qi, int qj, 
                                vector<vector<int>> &segTree) {
        if (sj < qi || si > qj) // no overlapping
            return {INT_MAX, INT_MIN}; 
            
        if (si >= qi && sj <= qj) // complete overlapping
            return segTree[i];
        
        int mid = (si + sj) / 2;
        auto l = getMinMaxUtil(2 * i + 1, si, mid, qi, qj, segTree);
        auto r = getMinMaxUtil(2 * i + 2, mid + 1, sj, qi, qj, segTree);
        return {min(l[0], r[0]), max(l[1], r[1])};
    }
    
    vector<int> getMinMax(vector<int>& arr, int L, int R,
                          vector<vector<int>>& segTree) {
        // code here
        int n = arr.size();
        return getMinMaxUtil(0, 0, n - 1, L, R, segTree);
    }

    // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    vector<int> updateValueUtil(int i, int si, int sj, int &idx, int &val, 
                            vector<vector<int>>& segTree) {
        if (idx < si || idx > sj) // no overlapping
            return segTree[i];
        
        if (si == sj)
            return segTree[i] = {val, val}; // leaf node
        
        int mid = (si + sj) / 2;
        auto l = updateValueUtil(2 * i + 1, si, mid, idx, val, segTree);
        auto r = updateValueUtil(2 * i + 2, mid + 1, sj, idx, val, segTree);
        return segTree[i] = {min(l[0], r[0]), max(l[1], r[1])};
    }
    
    void updateValue(vector<int>& arr, int index, int value,
                     vector<vector<int>>& segTree) {

        // code here
        int n = arr.size();
        arr[index] = value;
        updateValueUtil(0, 0, n - 1, index, value, segTree);
        // print(arr);
    }
};