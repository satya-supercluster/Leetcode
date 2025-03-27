class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxRight(n,nums[n-1]),maxLeft(n,nums[0]);
        for(int i{1};i<n;i++){
            maxLeft[i]=max(maxLeft[i-1],nums[i]);
        }
        for(int i{n-2};i>=0;i--){
            maxRight[i]=max(maxRight[i+1],nums[i]);
        }
        long long score{0};
        for(int i{1};i<n-1;i++){
            score=max(score,(maxLeft[i-1]-nums[i])*1ll*maxRight[i+1]);
        }
        return score;
    }
};