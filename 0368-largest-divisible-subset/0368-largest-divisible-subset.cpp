class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {}; 
        sort(nums.begin(), nums.end());  
        vector<int> v(n, 1), v2(n, -1);
        int maxLen = 1, maxi = 0; 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && v[j] + 1 > v[i]) {
                    v[i] = v[j] + 1;
                    v2[i] = j;
                }
            }
            if (v[i] > maxLen) {
                maxLen = v[i];
                maxi = i;
            }
        } 
        vector<int> ans;
        while (maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = v2[maxi];
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};