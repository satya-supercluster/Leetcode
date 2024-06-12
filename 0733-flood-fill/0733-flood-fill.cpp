class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> ans;
    int m,n,cl;
    void dfs(int sr, int sc,vector<vector<int>>& img){
        int c=img[sr][sc];
        ans[sr][sc]=cl;
        for(int i{};i<4;i++){
            int x=sr+dir[i].first;
            int y=sc+dir[i].second;
            if(x>=0 and x<m and y>=0 and y<n and c==img[x][y] and ans[x][y]!=cl){
                dfs(x,y,img);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int c) {
        m=img.size();n=img[0].size();cl=c;ans=img;
        dfs(sr,sc,img);
        return ans;
    }
};