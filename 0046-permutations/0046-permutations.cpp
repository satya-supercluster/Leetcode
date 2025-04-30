class Solution {
public:
    void solve(int i, int n, vector<vector<int>>& ans, vector<int>& nums){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            solve(i+1, n, ans, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0, n, ans, nums);
        return ans;    
    }
};