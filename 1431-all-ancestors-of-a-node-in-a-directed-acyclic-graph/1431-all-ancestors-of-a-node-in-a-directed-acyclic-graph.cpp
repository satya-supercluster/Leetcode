class Solution {
public:
    vector<int> merge(vector<int>&a,vector<int>&b){
        set<int>s;
        for(auto&i:a)s.insert(i);
        for(auto&i:b)s.insert(i);
        vector<int> ans(begin(s),end(s));
        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<vector<int>>ans(n);
        while(!q.empty()){
            auto e=q.front();
            q.pop();
            for(auto&child:adj[e]){
                vector<int> temp=ans[e];
                temp.push_back(e);
                ans[child]=merge(temp,ans[child]);
                indeg[child]--;
                if(indeg[child]==0){
                    q.push(child);
                }
            }
        }
        return ans;
    }
};