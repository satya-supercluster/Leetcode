class Solution {
public:
    bool isVowel(char i){
        if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int mn{},c{};
        for(int i{};i<k;i++){
            if(isVowel(s[i])) c++;
        }
        mn=c;
        for(int i{k};i<s.length();i++){
            if(isVowel(s[i])) c++;
            if(isVowel(s[i-k])) c--;
            mn=max(mn,c);
        }
        return mn;
    }
};