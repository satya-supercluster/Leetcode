class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        if(*s.begin()==k){
            return s.size()-1;
        }
        else if(*s.begin()>k){
            return s.size();
        }
        return -1;
    }
};