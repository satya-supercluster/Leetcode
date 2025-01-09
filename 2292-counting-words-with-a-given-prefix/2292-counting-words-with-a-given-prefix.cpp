class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int k=pref.length();
        int c{};
        for(auto&i:words){
            if(i.length()>=k and i.substr(0,k)==pref) c++;
        }
        return c;
    }
};