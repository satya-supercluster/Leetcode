class Solution {
    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int ans{},c{},n,m;
public:
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid){
        vis[i][j]=1;
        c++;
        for(auto&d:dir){
            int x=i+d.first;
            int y=j+d.second;
            if(x>=0 and x<n and y>=0 and y<m and (!vis[x][y]) and grid[x][y]){
                dfs(x,y,vis,grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if(grid[i][j] and (!vis[i][j])){
                    c=0;
                    dfs(i,j,vis,grid);
                    ans=max(ans,c);
                }
            }
        } 
        return ans;
    }
};