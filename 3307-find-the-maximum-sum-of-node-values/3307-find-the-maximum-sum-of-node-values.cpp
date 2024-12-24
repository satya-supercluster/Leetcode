class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> curr(2,0),next(2,0);
        // base cases
        next[0] = -1e9;
        next[1] = 0;
        for(int idx=n-1;idx>=0;--idx) {
            for(int even=0;even<2;++even) {
                long long take = (nums[idx]^k) + next[even^1]; 
                long long notTake = nums[idx] + next[even];

                curr[even] = max(take,notTake);
            }
            next = curr;
        }
        return curr[1];        
    }
};