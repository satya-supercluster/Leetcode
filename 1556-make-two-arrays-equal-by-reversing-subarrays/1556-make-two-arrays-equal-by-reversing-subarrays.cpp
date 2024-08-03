class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>s1,s2;
        for(auto&i:target)s1[i]++;
        for(auto&i:arr)s2[i]++;
        return s1==s2;
    }
};