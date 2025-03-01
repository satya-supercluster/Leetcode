class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int ind{},n=nums.size();
        vector<int> v;
        for(int i{};i<n-1;i++){
            if(nums[i]==nums[i+1] and nums[i]){
                v.push_back(nums[i]*2ll);
                nums[i+1]=0;
            }
            else if(nums[i]) v.push_back(nums[i]);
        }
        if(nums.back()) v.push_back(nums.back());
        while(v.size()<n) v.push_back(0);
        return v;
    }
};