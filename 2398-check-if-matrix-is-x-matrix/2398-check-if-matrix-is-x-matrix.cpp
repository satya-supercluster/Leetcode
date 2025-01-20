class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i{};i<n;i++){
            for(int j{};j<n;j++){
                if((i==j) or (i==(n-1-j))){ if(!mat[i][j]) return false; }
                else if(mat[i][j]) return false;
            }
        }
        return true;
    }
};