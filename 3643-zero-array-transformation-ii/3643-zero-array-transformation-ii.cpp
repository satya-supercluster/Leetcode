class Solution {
public:
    int solve(vector<int> nums, vector<vector<int>>& queries,int mid) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(int i{};i<=mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]-=val;
            diff[r+1]+=val;
        }
        for(int i{1};i<=n;i++){
            diff[i]+=diff[i-1];
        }
        for(int i{};i<n;i++){
            nums[i]=nums[i]+diff[i];
            if(nums[i]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size(),k{-1};
        if(solve(nums,queries,-1)) return 0;
        int s=0,e=m-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(solve(nums,queries,mid)){
                k=mid+1;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return k;
    }
};