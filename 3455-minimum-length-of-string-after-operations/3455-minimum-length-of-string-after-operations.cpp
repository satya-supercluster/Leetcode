class Solution {
public:
    static int minimumLength(string& s) {
        int freq[26]={0};
        for(char c: s)
            freq[c-'a']++;
        int len=0;
        for(int i=0; i<26; i++){
            if (freq[i]==0) continue;
            len+=2-(freq[i]&1);
        }
        return len;
    }
};