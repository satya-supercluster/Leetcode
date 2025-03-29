class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, bool> bl;
        int mx = 0;
        
        for (int i : nums) {
            if (bl[i]) {
                continue;
            }
            bl[i] = true;
            int l = i, r = i;
            
            if (mp.find(i + 1) != mp.end()) {
                r = mp[i + 1].first;
            }
            if (mp.find(i - 1) != mp.end()) {
                l = mp[i - 1].second;
            }
            mp[r] = make_pair(r, l);
            mp[l] = make_pair(r, l);
            mx = max(mx, r - l + 1);
        }
        
        return mx;
    }
};