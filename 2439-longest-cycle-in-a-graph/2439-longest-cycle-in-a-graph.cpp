class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,int&cycle,int par){
        vis[node]=true;
        cycle++;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,cycle,node))return true;
            }
            else if(it!=par)return true;
            else if(it==par){cycle=2;return true;}
        }
        //backtracking: didn't get cycle 
        vis[node]=false;
        cycle--;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[edges[i]].push_back(i);// reversing the graph 
            }
        }
        int maxi=-1;
        vector<int>vis(n,false);
        for(int i=0;i<n;i++){
            //making dfs calls for unvisited nodes
            if(!vis[i]){
                int val=0;
                // if cycle is present updating maxi
                if(dfs(i,adj,vis,val,-1))maxi=max(maxi,val);
            }
        }
        return maxi;
    }
};