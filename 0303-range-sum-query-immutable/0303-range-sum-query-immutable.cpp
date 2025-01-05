class NumArray {
    int n;
    vector<int> bit;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        bit.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            updateBIT(i + 1, nums[i]);
        }
    }
    
    void updateBIT(int i, int diff) {
        while(i <= n) {
            bit[i] += diff;
            i += (i & -i);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateBIT(index + 1, diff);
    }
    
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};