class Solution {
public:
    void dfs(int it,vector<int>&vis,vector<vector<int>>&adj,vector<int>&comp,int &e){
        vis[it]=1;
        comp.push_back(it);
        for(auto&child:adj[it]){
            e++;
            if(!vis[child]){
                dfs(child,vis,adj,comp,e);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>>components;
        vector<int> compEdgeCount;
        vector<int> vis(n,0);
        for(int i{};i<n;i++){
            if(!vis[i]){
                vector<int> component;
                int e{};
                dfs(i,vis,adj,component,e);
                components.push_back(component);
                compEdgeCount.push_back(e/2);
            }
        }
        int reqConnection=components.size()-1;
        int possDisconnection{};
        for(int i{};i<components.size();i++){
            int s=components[i].size();
            s--;
            possDisconnection+=(compEdgeCount[i]-s);
        }
        // for(auto&comp:components){
        //     for(auto&i:comp){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<possDisconnection<<" "<<reqConnection<<endl;
        if(possDisconnection<reqConnection){
            return -1;
        }
        else return reqConnection;
    }
};