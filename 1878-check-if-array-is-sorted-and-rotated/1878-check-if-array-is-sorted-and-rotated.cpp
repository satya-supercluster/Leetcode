class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int in{-1};
        for(int i{1};i<n;i++){
            if(nums[i]<nums[i-1]) in=i;
        }
        if(in==-1) return true;
        for(int i{0};i<n-1;i++){
            if(nums[(in+i)%n]>nums[(in+i+1)%n]) return false;
        }
        return true;
    }
};