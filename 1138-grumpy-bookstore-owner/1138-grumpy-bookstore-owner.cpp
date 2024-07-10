class Solution {
public:
    int maxSatisfied(vector<int>& ct, vector<int>& g, int m) {
        int ans{};
        int n=ct.size();
        for(int i{};i<n;i++){
            if(g[i]==0)ans+=ct[i];
        }
        int mx=-1,sum{};
        int i{};
        for(int j{};j<n;j++){
            if(j<m-1){
                if(g[j])sum+=ct[j];
                mx=max(mx,sum);
                continue;
            }
            if(g[j])sum+=ct[j];
            mx=max(mx,sum);
            if((j-i+1)==m){
                mx=max(mx,sum);
                if(g[i])sum-=ct[i];
                i++;
            }
            else if((j-i+1)<m){
                if(g[j])sum+=ct[j];
                mx=max(mx,sum);
            }
            
            // cout<<sum<<" ";
        }
        return mx+ans;
    }
};