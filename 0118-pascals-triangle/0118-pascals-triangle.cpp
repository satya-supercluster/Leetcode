class Solution {
public:
    vector<vector<int>> pre;
    int p=1;
    void calci(){
        int i=3;
        while(i<=30){
            vector<int> v(i,1);
            for(int k=1;k<i-1;k++){
                v[k]=pre[i-1][k-1]+pre[i-1][k];
            }
            i++;
            pre.push_back(v);
        }
    }
    vector<vector<int>> generate(int numRows) {
        if(p){
            pre.push_back({});
            pre.push_back({1});
            pre.push_back({1,1});
            calci();
            p=0;
        }
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(pre[i]);
        }
        return ans;
    }
};