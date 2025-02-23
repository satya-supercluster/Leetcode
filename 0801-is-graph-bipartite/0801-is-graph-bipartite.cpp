class Solution {
    vector<int> col;
    vector<int> vis;
    int n;
    bool final;
public:
    void dfs(int u,vector<vector<int>>&adj){
        vis[u]=true;
        for(auto&child:adj[u]){
            if(!vis[child]){
                col[child]=(col[u]==0)?1:0;
                dfs(child,adj);
            }
            else if(col[child]==col[u]) {
                final=false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        n=adj.size();
        col.resize(n);
        for(auto&i:col) i=-1;
        vis.resize(n);
        for(auto&i:vis) i=false;
        final=true;
        for(int i{};i<n;i++){
            if(!vis[i]){
                col[i]=0;
                dfs(i,adj);
            }
        }
        return final;
    }
};