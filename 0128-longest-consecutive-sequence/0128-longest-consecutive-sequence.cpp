class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.size() < 2) return nums.size();
        std::unordered_set<int> ints(nums.begin(), nums.end());
        int currentMaxSequence = 0;
        for(auto num : ints){
            if(ints.find(num-1) != ints.end()) continue;
            int seq = 1;
            while(ints.find(++num) != ints.end()) seq++;
            currentMaxSequence = std::max(currentMaxSequence, seq);
        }
        return currentMaxSequence;
    }
};