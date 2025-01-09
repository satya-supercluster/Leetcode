class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string s2;
        for(auto&i:words) {
            s2+=i;
            if(s2==s) return true;
        }
        return false;
    }
};