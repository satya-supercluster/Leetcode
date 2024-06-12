class Solution {
public:
    vector<int> vis;
    void dfs(int i,vector<vector<int>>& g){
        vis[i]=1;
        for(int k{};k<g.size();k++){
            if(g[i][k]==1 and !vis[k])dfs(k,g);
        }
    }
    int findCircleNum(vector<vector<int>>& g) {
        vis.resize(g.size());
        int ans{};
        for(int i{};i<g.size();i++){
            if(!vis[i]){
                ans++;
                dfs(i,g);
            }
        }
        return ans;
    }
};