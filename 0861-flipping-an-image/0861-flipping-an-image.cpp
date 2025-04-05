class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>> ans = image;

        for(int i=0;i<n;i++) {
            reverse(ans[i].begin(), ans[i].end());
            for(int j=0;j<n;j++) {
                if(ans[i][j] == 0){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
    }
};