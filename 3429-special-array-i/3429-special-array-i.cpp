class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i{};i<nums.size()-1;i++) if((nums[i]&1ll)==(nums[i+1]&1ll)) return false;
        return true;
    }
};