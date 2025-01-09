class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int k=s.length();
        int c{};
        for(auto&i:words){
            if(i.length()<=k and s.substr(0,i.length())==i) c++;
        }
        return c;
    }
};