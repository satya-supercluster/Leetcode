class Solution {
public:
    int maximumSum(vector<int>& nums) {
        auto smd=[](int x)->int{
            int sum{};
            while(x){
                sum+=x%10;
                x/=10;
            }
            return sum;
        };
        map<int,int> mp;
        int n=nums.size(),ans{-1};
        for(int i{};i<n;i++){
            int p=smd(nums[i]);
            if(mp.count(p)){
                ans=max(mp[p]+nums[i],ans);
            }
            mp[p]=max(mp[p],nums[i]);
        }
        return ans;
    }
};