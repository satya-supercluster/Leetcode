class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(auto&i:matrix){
            set<int> st;
            for(auto&j:i) st.insert(j);
            if(st.size()!=n) return false;
        }
        for(int i{};i<n;i++){
            set<int> st;
            for(int j{};j<n;j++){
                st.insert(matrix[j][i]);
            }
            if(st.size()!=n) return false;
        }
        return true;
    }
};