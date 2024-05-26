class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
        int p=1;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                mp[p]=i;
                p++;
            }
        }
        for(;p<=n+1;p++){
            mp[p]=-1;
        }
        for(auto&i:queries){
            i=min(i,n+1);
            ans.push_back(mp[i]);
        }
        return ans;
    }
};