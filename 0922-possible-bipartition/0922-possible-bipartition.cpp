class Solution {
    vector<int> col;
    vector<int> vis;
    vector<vector<int>> adj;
    int n;
    int final;
public:
    void dfs(int u){
        vis[u]=true;
        for(auto child:adj[u]){
            if(!vis[child]){
                col[child]=(col[u]==0)?1:0;
                dfs(child);
            }
            else if(col[child]==col[u]){
                final=false;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        this->n=n;
        col.resize(n+1);
        for(auto&i:col) i=-1;
        vis.resize(n+1);
        for(auto&i:vis) i=false;
        adj.resize(n+1);
        for(auto&edge:dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        final=true;
        for(int i{1};i<=n;i++){
            if(!vis[i]){
                col[i]=0;
                dfs(i);
            }
        }
        return final;
    }
};