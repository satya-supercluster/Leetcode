class Solution {
public:
    set<int> dfs(int i, vector<vector<int>>& parents, vector<vector<int>>& adj){
        set<int> s;
        for(auto it : adj[i]){
            if(parents[it].size() == 0){
                set<int> t =  dfs(it,parents,adj);
                s.insert(t.begin(),t.end());
            }
            else{
                s.insert(parents[it].begin(),parents[it].end());
                s.insert(it);
            }
        }
        parents[i] = {s.begin(),s.end()};
        s.insert(i);
        return s;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> parents(n);
        // vector<set> parents(n);
        vector<vector<int>> adj(n);
        vector<int> outDeg(n,0);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            outDeg[it[0]]++;
        }
        for(int i = 0; i < n; i++){
            if(outDeg[i] == 0){
                set<int> temp = dfs(i,parents,adj);
            }
        }
        return parents;
    }
};