class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> ctr;
        for (int num : nums)
            ctr[num]++;
        for (int num : nums) {
            int start = num;
            while (ctr[start - 1])
                start--;
            for (; start <= num; start++) {
                int times = ctr[start];
                if (times) {
                    for (int victim = start; victim < start + k; victim++) {
                        if (ctr[victim] < times)
                            return false;
                        ctr[victim] -= times;
                    }
                }
            }
        }
        return true;
    }
};