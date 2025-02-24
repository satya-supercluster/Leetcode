class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),c{},ans{};
        for(int i{};i<n;i++){
            if(nums[i]==1){
                c++;
                ans=max(ans,c);
            }
            else c=0;
        }
        return ans;
    }
};