class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans{1},curr{1},n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        for(int i{1};i<n;i++){
            if(nums[i]==nums[i-1] and nums[i]==mx){
                curr++;
                ans=max(ans,curr);
            }
            else{
                curr=1;
            }
        }
        return ans;
    }
};