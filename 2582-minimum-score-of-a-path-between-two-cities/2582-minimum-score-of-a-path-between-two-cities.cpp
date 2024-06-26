class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto&vec:roads){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }
        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            int sz=q.size();
            for(int i{};i<sz;i++){
                int ele=q.front();
                q.pop();
                for(auto&pr:adj[ele]){
                    int v=pr.first,w=pr.second;
                    ans=min(ans,w);
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
        }
        return ans;
    }
};