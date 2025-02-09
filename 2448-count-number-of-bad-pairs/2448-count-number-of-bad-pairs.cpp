class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long ans{(n*1ll*(n-1))/2ll};
        map<long long,int> mp;
        for(long long i{};i<n;i++){
            if(mp.count(i-nums[i])) ans-=mp[i-nums[i]];
            mp[i-nums[i]]++;
        }
        return ans;
    }
};