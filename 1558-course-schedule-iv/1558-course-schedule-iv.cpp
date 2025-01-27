class Solution {
public:

    bool dfs(unordered_map<int,vector<int>> &m, int node, vector<int> &vis, int target){
        if(node==target) return true;
        vis[node] = 1;
        for(auto i:m[node]){
            if(vis[i]==-1){
                if(dfs(m,i,vis,target)) return true;
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& arr, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int,vector<int>> m;
        for(auto i:arr){
            m[i[0]].push_back(i[1]);
        }
        for(auto i:queries){
            vector<int> vis(n,-1);
            ans.push_back(dfs(m,i[0],vis,i[1]));
        }
        return ans;
    }
};