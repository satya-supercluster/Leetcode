class Solution {
public:
    void dfs(int node, vector<pair<int,int>>adj[], vector<int>&vis, int &c){
        vis[node]=1;
        for(auto it: adj[node]){
            int v=it.first;
            int dir=it.second;
            if(!vis[v]){
                if(dir==1)c++;
                dfs(v,adj,vis,c);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,2});
        }
        
        int c=0;
        vector<int>vis(n,0);
        dfs(0,adj,vis,c);
        return c;
    }
};