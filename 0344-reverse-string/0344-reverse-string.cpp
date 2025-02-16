class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1,m=0;
        while(m<=n){
            swap(s[m],s[n]);
            m++;
            n--;
        }
    }
};