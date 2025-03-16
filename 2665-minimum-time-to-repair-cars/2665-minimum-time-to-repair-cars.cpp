class Solution {
public:
    int n;
    bool CheckAllCarRepairPossible(vector<int>& ranks, long long time, int cars) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sqrt(time / ranks[i]);
            if (sum >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = *max_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        n = ranks.size();
        long long ans = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (CheckAllCarRepairPossible(ranks, mid, cars)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};