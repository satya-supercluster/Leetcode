class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),ans{};
        int p=0;
        for(int i=0;i<n;i++)if(nums[i]>=0)p=1;
        if(!p){
            return *max_element(begin(nums),end(nums));
        }
        int i=0,sum=0;
        for(int k=0;k<n;k++){
            sum+=nums[k];
            if(sum>=0){
                ans=max(ans,sum);
            }
            else sum=0;
        }
        return ans;
    }
};