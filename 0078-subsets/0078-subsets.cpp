class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i{};i<(1ll<<n);i++){
            vector<int> v;
            for(int j{};j<n;j++){
                if((i>>j)&1ll){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};