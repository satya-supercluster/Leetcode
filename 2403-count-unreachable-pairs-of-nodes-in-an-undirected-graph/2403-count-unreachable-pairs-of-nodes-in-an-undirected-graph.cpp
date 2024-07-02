class Solution {
public:
    void dfs(int i,long long&comp,vector<bool>&vis, vector<vector<int>>& adj){
        vis[i]=true;
        comp++;
        for(auto child:adj[i]){
            if(!vis[child])dfs(child,comp,vis,adj);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<long long> components;
        vector<bool>vis(adj.size(),false);
        for(int i{};i<adj.size();i++){
            if(!vis[i]){
                long long comp{};
                dfs(i,comp,vis,adj);
                components.push_back(comp);
            }
        }
        vector<int> suffix(components.size());
        suffix[components.size()-1]=components.back();
        for(int i=components.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]+components[i];
        }
        long long ans{};
        for(int i{};i<components.size()-1;i++){
            ans=ans+1ll*components[i]*suffix[i+1];
        }
        // for(auto&comp:components){
        //     cout<<comp<<" ";
        // }
        // cout<<endl;
        // for(auto&comp:suffix){
        //     cout<<comp<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};