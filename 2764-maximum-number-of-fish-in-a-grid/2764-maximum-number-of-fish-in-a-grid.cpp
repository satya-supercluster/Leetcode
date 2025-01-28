class Solution {
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans{},temp{};
        function<void(int,int)> dfs=[&](int i,int j)->void{
            vis[i][j]=true;
            temp+=grid[i][j];
            for(auto&d:dir){
                int x=i+d.first;
                int y=j+d.second;
                if(x>=0 and x<n and y>=0 and y<m and (!vis[x][y]) and (grid[x][y]!=0)){
                    dfs(x,y);
                }
            }
            ans=max(ans,temp);
        };

        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if((!vis[i][j]) and (grid[i][j]!=0)){
                    temp=0;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};