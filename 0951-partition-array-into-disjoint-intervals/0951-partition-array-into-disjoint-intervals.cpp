class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> minRight(n,nums[n-1]),maxLeft(n,nums[0]);
        for(int i{1};i<n;i++){
            maxLeft[i]=max(maxLeft[i-1],nums[i]);
        }
        for(int i{n-2};i>=0;i--){
            minRight[i]=min(minRight[i+1],nums[i]);
        }
        for(int i{};i<n-1;i++){
            if(maxLeft[i]<=minRight[i+1]) return i+1;
        }
        return -1;
    }
};