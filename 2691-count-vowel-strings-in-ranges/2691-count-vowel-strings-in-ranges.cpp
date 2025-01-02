class Solution {
    bool isVowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> v;
        int n=w.size();
        for(int i{};i<n;i++){
            if(isVowel(w[i][0]) and isVowel(w[i][w[i].size()-1])) v.push_back(1);
            else v.push_back(0);
        }
        for(int i{1};i<n;i++) v[i]+=v[i-1];
        vector<int> ans;
        for(auto&u:q){
            int l=u[0],r=u[1];
            if(l==0) ans.push_back(v[r]);
            else ans.push_back(v[r]-v[l-1]);
        }
        return ans;
    }
};