class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans{};
        vector<int>pre(nums.size(),0);
        pre[0]=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+(nums[i]%2);
        }
        
        // for(int i{};i<nums.size();i++){
        //     cout<<pre[i]<<" ";
        // }
        for(int i{};i<nums.size();i++){
            if(pre[i]>=k){
                ans+=mp[pre[i]-k]+(pre[i]==k);
                // cout<<mp[pre[i]-k]<<endl;
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};