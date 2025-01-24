class Solution {
    vector<int> ans;
    vector<vector<int>> adj;
    int n;
    vector<int> vis;
public:
    void dfs(int u){
        bool p=true;
        vis[u]=true;
        for(auto&i:adj[u]){
            if(vis[i]){
                p&=ans[i];
            }
            else{
                dfs(i);
                p&=ans[i];
            }
        }
        ans[u]=p;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj=graph;
        int n=adj.size();
        vis.resize(n);
        ans.resize(n);
        for(int i{};i<n;i++) if(!vis[i]) dfs(i);
        vector<int> res;
        for(int i{};i<n;i++) if(ans[i]) res.push_back(i);
        return res;
    }
};