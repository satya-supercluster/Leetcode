class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size(),ans{};
        for(int j{};j<n;j++){
            for(int i{};i<j;i++){
                if(nums[i]==nums[j] and (i*j)%k==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};