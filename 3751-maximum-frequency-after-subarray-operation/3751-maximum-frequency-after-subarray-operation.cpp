class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        unordered_map<int, int> count;
        for (int a : A) {
            count[a]++;
        }

        auto kadane = [&](int b) {
            int res = 0, cur = 0;
            for (int a : A) {
                if (a == k) {
                    cur--;
                }
                if (a == b) {
                    cur++;
                }
                if (cur < 0) {
                    cur = 0;
                }
                res = max(res, cur);
            }
            return res;
        };

        int res = 0;
        for (const auto& [b, _] : count) {
            res = max(res, kadane(b));
        }
        return count[k] + res;
    }
};