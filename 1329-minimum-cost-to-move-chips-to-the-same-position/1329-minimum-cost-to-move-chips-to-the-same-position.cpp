class Solution {
public:
    int minCostToMoveChips(vector<int>& v) {
        int c0{},c1{};
        for(auto&i:v) i%=2,c0+=!i,c1+=i;
        return min({c0,c1});
    }
};