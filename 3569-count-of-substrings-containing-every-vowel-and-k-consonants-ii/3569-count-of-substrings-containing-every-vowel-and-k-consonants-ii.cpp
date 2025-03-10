class Solution {
public:
    bool isVowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return true;
        return false;
    }
    long long solve(string word, int k) {
        map<char,int> vow;
        long long cons{},i{},ans{};
        for(int j{};j<word.length();j++){
            if(isVowel(word[j])) vow[word[j]]++;
            else cons++;
            while(cons>=k and vow.size()==5 and i<j){
                ans+=word.length()-j;
                if(isVowel(word[i])) {
                    vow[word[i]]--;
                    if(vow[word[i]]==0) vow.erase(word[i]);
                }
                else cons--;
                i++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word,k)-solve(word,k+1);
    }
};