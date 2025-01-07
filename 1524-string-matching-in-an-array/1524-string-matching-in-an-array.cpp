class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i{};i<words.size();i++){
            for(int j{};j<words.size();j++){
                if (i != j) {
                    auto found = words[j].find(words[i]);
                    if (found != string::npos) {
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};