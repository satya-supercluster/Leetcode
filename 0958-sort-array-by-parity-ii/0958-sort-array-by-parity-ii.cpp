class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int e=0,o=1;
        for(int i{};i<nums.size();i++){
            if(nums[i]%2){
                ans[o]=nums[i];
                o+=2;
            }
            else {
                ans[e]=nums[i];
                e+=2;
            }
        }
        return ans;
    }
};