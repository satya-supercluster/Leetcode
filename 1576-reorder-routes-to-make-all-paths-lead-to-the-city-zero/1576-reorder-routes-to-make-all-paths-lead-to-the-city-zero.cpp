class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],2});
        }
        vector<int> vis(n,0);
        int ct{};
        function<void(int)> dfs=[&](int i)->void{
            vis[i]=1;
            // cout<<i<<" "<<ct<<endl;
            for(auto&child:adj[i]){
                if(!vis[child.first]){
                    if(child.second==1) ct++;
                    dfs(child.first);
                }
            }
            // cout<<i<<" "<<ct<<": end"<<endl;
        };
        dfs(0);
        return ct;
    }
};