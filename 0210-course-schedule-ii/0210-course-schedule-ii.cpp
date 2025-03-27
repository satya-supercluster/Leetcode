class Solution {
    int cycle=false;
public:
    void dfs(int u,stack<int>&st,vector<int>&vis,vector<vector<int>>&adj){
        vis[u]=1;
        for(auto&child:adj[u]){
            if(!vis[child]){
                dfs(child,st,vis,adj);
            }
            else if(vis[child]==1) cycle=true;
        }
        vis[u]=2;
        st.push(u);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&edge:edges){
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> ans,vis(n,0);
        for(int i{};i<n;i++)
            if(!vis[i])
                dfs(i,st,vis,adj);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(cycle) return {};
        return ans;
    }
};