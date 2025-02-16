class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int e=1,o=0;
        for(int i{};i<nums.size();i++){
            if(nums[i]%2){
                ans[e]=nums[i];
                e+=2;
            }
            else {
                ans[o]=nums[i];
                o+=2;
            }
        }
        return ans;
    }
};