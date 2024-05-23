class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        int m=mt.size(),n=mt[0].size();
        vector<int> row(m,-1),col(n,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mt[i][j]==0)row[i]=col[j]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(row[i]==0){
                for(int j=0;j<n;j++)mt[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            if(col[i]==0){
                for(int j=0;j<m;j++)mt[j][i]=0;
            }
        }
    }
};