class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>col,ind;
        vector<int> re;
        for(auto t:queries){
            int in=t[0],c=t[1];
            if(ind[in]!=0){
                col[ind[in]]--;
                if(col[ind[in]]==0){
                    col.erase(ind[in]);
                }
                col[c]++;
                ind[in]=c;
            }
            else{
                ind[in]=c;
                col[c]++;
            }
            re.push_back(col.size());
        }
        return re;
    }
};