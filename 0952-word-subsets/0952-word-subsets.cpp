class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(),m=words2.size();
        vector<int> v(26,0);
        for(auto&i:words2){
            map<char,int>mp;
            for(auto&j:i) {
                mp[j]++;
                v[j-'a']=max(v[j-'a'],mp[j]);
            }
        }
        vector<string> ans;
        for(auto&i:words1){
            vector<int> v1(26,0);
            bool p=true;
            for(auto&j:i){
                v1[j-'a']++;
            }
            for(int k{};k<26;k++){
                if(v1[k]<v[k]) {
                    p=false;
                    break;
                }
            }
            if(p) ans.push_back(i);
        }
        return ans;
    }
};