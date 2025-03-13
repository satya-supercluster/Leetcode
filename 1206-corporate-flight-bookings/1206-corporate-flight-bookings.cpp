class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> diff(n+1,0);
        for(auto&i:b){
            int l=i[0],r=i[1],val=i[2];
            diff[l-1]+=val;
            diff[r]-=val;
        }
        for(int i{1};i<=n;i++) diff[i]+=diff[i-1];
        diff.pop_back();
        return diff;
    }
};