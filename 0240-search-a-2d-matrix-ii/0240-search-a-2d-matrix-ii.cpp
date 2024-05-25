class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size(),n=mat[0].size();
        int i=0,j=n-1;
        while(i<m and j>=0){
            if(mat[i][j]==t)return true;
            else if(mat[i][j]>t)j--;
            else i++;
        }
        return false;
    }
};