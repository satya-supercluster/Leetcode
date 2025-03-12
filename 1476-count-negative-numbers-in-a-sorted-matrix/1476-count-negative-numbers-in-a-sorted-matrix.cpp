class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int i=0,j=m-1,ans{};
        while(i<n and j>=0){
            if(grid[i][j]>=0){
                i++;
            }
            else{
                ans+=(n-i);
                j--;
            }
        }
        return ans;
    }
};