class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        vector<int> diff(n+1,0);
        diff[min(1,n)]+=1;
        diff[min(nums[0]+1,n)]-=1;
        for(int i{1};i<n;i++){
            if(i>0) diff[i]+=diff[i-1];
            if(diff[i]>0){
                if(nums[i]>0){
                    diff[min(i+1,n)]+=1;
                    diff[min(i+nums[i]+1,n)]-=1;
                }
            }
        }
        for(auto&i:diff) cout<<i<<" ";
        cout<<endl;
        if(diff[n-1]>0) return true;
        return false;
    }
};