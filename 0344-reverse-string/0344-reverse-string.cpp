class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i{};i<n/2;i++){
            s[i]=s[i]^s[n-1-i];
            s[n-i-1]=s[i]^s[n-1-i];
            s[i]=s[i]^s[n-1-i];
        }
    }
};