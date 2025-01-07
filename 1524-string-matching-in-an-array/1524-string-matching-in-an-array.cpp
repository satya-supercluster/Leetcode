class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        map<string,int> s;
        for(auto&word:words){
            for(int i{};i<word.length();i++){
                for(int j{i};j<word.length();j++){
                    s[word.substr(i,j-i+1)]++;
                }
            }
        }
        for(auto&word:words){ 
            if(s[word]>1) ans.push_back(word);
        }
        return ans;
    }
};