// leet 307
// https://leetcode.com/problems/range-sum-query-mutable/description/

class NumArray {
public:
    int n;
    vector<int> nums;
    vector<int> tree;

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        tree.resize(4 * n);

        for (int i = 0; i < 4 * n; i++)
            tree[i] = 0;

        create(0, 0, n - 1);
    }

    int create(int idx, int st, int end) {
        if (st == end)
            return tree[idx] = nums[st];
        
        int mid = (st + end) / 2;
        int left = create(2 * idx + 1, st, mid);
        int right = create(2 * idx + 2, mid + 1, end);
        return tree[idx] = left + right;
    }

    void updateUtil(int idx, const int &index, int st, int end, const int &diff) {
        if (st > index || end < index) 
            return;

        tree[idx] -= diff;

        if (st == end)
            return;
        
        int mid = (st + end) / 2;
        updateUtil(2 * idx + 1, index, st, mid, diff);
        updateUtil(2 * idx + 2, index, mid + 1, end, diff);
    }
    
    void update(int index, int val) {
        int diff = nums[index] - val;
        nums[index] = val;
        updateUtil(0, index, 0, n - 1, diff);
    }   

    int sumRangeUtil(int idx, int si, int sj, int qi, int qj) {
        if (si > qj || sj < qi) // non overlapping
            return 0;
        
        if (si >= qi && sj <= qj) // complete overlapping
            return tree[idx];
        
        int mid = (si + sj) / 2;
        int l = sumRangeUtil(2 * idx + 1, si, mid, qi, qj);
        int r = sumRangeUtil(2 * idx + 2, mid + 1, sj, qi, qj);
        return l + r;
    }
    
    int sumRange(int left, int right) {
        return sumRangeUtil(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 