class Solution {
public:
    int isPrefixOfWord(string sentence, string pref) {
        int k=pref.length();
        vector<string> words;
        string str;
        for(auto&i:sentence){
            if(i==' ') {
                words.push_back(str);
                str="";
            }
            else str.push_back(i);
        }
        words.push_back(str);
        int c{-1};
        for(int i{};i<words.size();i++){
            if(words[i].length()>=k and words[i].substr(0,k)==pref){
                c=i+1;
                break;
            }
        }
        return c;
    }
};