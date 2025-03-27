class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> minRight(n,nums[n-1]),minLeft(n,nums[0]);
        for(int i{1};i<n;i++){
            minLeft[i]=min(minLeft[i-1],nums[i]);
        }
        for(int i{n-2};i>=0;i--){
            minRight[i]=min(minRight[i+1],nums[i]);
        }
        int score{INT_MAX};
        bool ok=false;
        for(int i{1};i<n-1;i++){
            if(minLeft[i-1]<nums[i] and minRight[i+1]<nums[i]){
                score=min(score,nums[i]+minLeft[i-1]+minRight[i+1]);
                ok=true;
            }
        }
        if(ok) return score;
        return -1;
    }
};