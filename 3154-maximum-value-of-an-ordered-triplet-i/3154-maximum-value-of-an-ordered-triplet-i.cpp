class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long result = 0;
        vector<int> maxSuffix(n, 0);
        
        maxSuffix[n - 1] = 0;
        int maxSuf = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxSuffix[i] = maxSuf;
            maxSuf = max(maxSuf, nums[i]);
        }

        int maxPref = nums[0];
        for (int i = 1; i < n - 1; i++) { 
            long long tripletValue = (long long)(maxPref - nums[i]) * maxSuffix[i];
            result = max(result, tripletValue);
            maxPref = max(maxPref, nums[i]);
        }

        return result;
    }
};