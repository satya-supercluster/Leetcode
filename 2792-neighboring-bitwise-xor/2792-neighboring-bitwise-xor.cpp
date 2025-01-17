class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(int i{};i<derived.size();i++) x^=derived[i];
        if(x==0) return true;
        return false;
    }
};