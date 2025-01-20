class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum{};
        int n=mat.size();
        for(int i{};i<n;i++){
            for(int j{};j<n;j++){
                if((i==j) or (i==(n-1-j))) sum+=mat[i][j];
            }
        }
        return sum;
    }
};