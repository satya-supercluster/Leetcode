class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> r(n,0),c(m,0);
        for(int i{};i<n;i++){
            int sum{};
            for(int j{};j<m;j++){
                sum+=grid[i][j];
            }
            r[i]=sum;
        }
        for(int j{};j<m;j++){
            int sum{};
            for(int i{};i<n;i++){
                sum+=grid[i][j];
            }
            c[j]=sum;
        }
        int ans{};
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if(grid[i][j] and (r[i]>1 or c[j]>1)) ans++;
            }
        }
        return ans;
    }
};