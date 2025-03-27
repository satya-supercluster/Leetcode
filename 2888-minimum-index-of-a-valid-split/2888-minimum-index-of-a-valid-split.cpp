class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size(),x{-1};
        for(auto&i:nums) {
            mp[i]++;
            if(mp[i]>n/2) x=i;
        }
        if(x==-1) return x;
        int cnt=mp[x],left{};
        for(int i{};i<n;i++){
            if(nums[i]==x) left++;
            int leftSize=i+1,rightSize=n-i-1,right=cnt-left;
            if(left>leftSize/2 and right>rightSize/2){
                return i;
            }
        }
        return -1;
    }
};