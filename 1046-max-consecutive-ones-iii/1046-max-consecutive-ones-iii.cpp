class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count{},ans{};
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[j]) j++;
            else if(k>0){
                j++;
                k--;
            }
            else{
                ans=max(ans,j-i);
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};