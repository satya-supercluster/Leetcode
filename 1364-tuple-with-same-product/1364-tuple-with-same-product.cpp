class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans{};
        map<long long int,int>mp;
        for(int i{};i<n;i++){
            map<long long int,int>mp1;
            for(int j{0};j<i;j++){
                long long int mult=nums[i]*1ll*nums[j];
                mp1[mult]++;
                if(mp.count(mult))ans+=(mp[mult]*8ll);
            }
            for(auto&[i,j]:mp1){
                mp[i]+=j;
            }
        }
        return ans;
    }
};