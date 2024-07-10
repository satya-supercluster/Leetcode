class Solution {
public:
    int longestSubarray(vector<int>& nums, int l) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqs;
        int i;
        int ans{};
        int low{-1};
        for(i=0;i<n;i++){
            pq.push({nums[i],i});
            pqs.push({nums[i],i});
            while((!pq.empty()) and pq.top().second<=low){
                pq.pop();
            }
            while((!pqs.empty()) and pqs.top().second<=low){
                pqs.pop();
            }
            int g=pq.top().first;
            int s=pqs.top().first;
            // cout<<s<<" "<<g<<" ";
            int d=abs(g-s);
            if(d<=l){
                if(low==-1){
                    ans++;
                }
                else{
                    ans=max(ans,i-low);
                }
            }
            else{
                int mn=min(pq.top().second,pqs.top().second);
                while((!pq.empty()) and pq.top().second<=mn){
                    pq.pop();
                }
                while((!pqs.empty()) and pqs.top().second<=mn){
                    pqs.pop();
                }
                low=mn;
            }
            // cout<<ans<<" "<<low<<endl;
        }
        return ans;
    }
};