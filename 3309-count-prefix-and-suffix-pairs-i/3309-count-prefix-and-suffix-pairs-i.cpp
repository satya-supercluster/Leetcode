class Solution {
public:
    bool check(string&a,string&b){
        if(a.length()>b.length())return false;
        if(a==b.substr(0,a.length()) and a==b.substr(b.length()-a.length())) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans{},n=words.size();
        for(int i{};i<n;i++){
            for(int j{i+1};j<n;j++){
                if(check(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};