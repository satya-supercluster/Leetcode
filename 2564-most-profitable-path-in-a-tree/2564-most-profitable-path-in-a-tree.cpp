class Solution {

     void dfs(int node, auto &gr, int bob, auto &curr,vector<int>&path,int par = -1){
       
        curr.push_back(node);
        if(node == bob){
            path = curr ;
             return ;
        }

        for(int x:gr[node]){
            
            if(x != par){
                dfs(x,gr,bob,curr,path,node);
            }
        }
        curr.pop_back();
         
     }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {


      int ans = -1e9 ;
      int n = edges.size()+1;
      vector<vector<int>>gr(n);

      for(auto x:edges){
         gr[x[0]].push_back(x[1]);
         gr[x[1]].push_back(x[0]);
      }
        vector<int>curr,path; 
        dfs(0,gr,bob,curr,path) ;  
        reverse(path.begin(),path.end());
        vector<int>dis(n,n+1) ;

        for(int i=0;i<path.size();i++){
            dis[path[i]] = i ;
        }

        queue<vector<int>>q; 
        vector<int>vis(n,0);
        q.push({amount[0],0,0}); // amount, dis ,node 
        
        while(!q.empty()){
         
          auto p = q.front();
          q.pop();
          int currSum = p[0];
          int d = p[1];
          int node = p[2];
          vis[node] =1 ;
          int child = 0;
          for(int x:gr[node]){

             if(!vis[x]){
                child++;
                int temp= ((d+1) < dis[x]  ? amount[x] : ((d+1) > dis[x] ? 0: amount[x]/2));
                 q.push({currSum+temp,d+1,x});
             }
          }

          if(child == 0){
             ans = max(ans,currSum);
          }
        }
   
        return ans ;

    }
};