class Solution {
public:
    const int maxN = 100001;
    const int MOD = 1000000007;

    long power(long base, long exponent) {
        long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> isPrime(maxN, 1), primeScore(maxN, 0);
        isPrime[0] = isPrime[1] = 0;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < maxN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < maxN; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        for (int i = 2; i < maxN; i++) {
            if (isPrime[i]) {
                for (int j = i; j < maxN; j += i) {
                    primeScore[j]++;
                }
            }
        }

        int n = nums.size();
        vector<int> nge(n, n), pge(n, -1);
        stack<int> st;

        // Next greater element based on prime score
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScore[nums[st.top()]] <= primeScore[nums[i]]) 
                st.pop();
            if (!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        // Previous greater element based on prime score
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScore[nums[st.top()]] < primeScore[nums[i]]) 
                st.pop();
            if (!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        vector<long> temp(n);
        for (int i = 0; i < n; i++) {
            long left = (i - pge[i]);
            long right = (nge[i] - i);
            temp[i] = left * right;
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long ans = 1;
        while (k > 0 && !pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            long op = min((long)k, temp[idx]);
            ans = (ans * power(val, op)) % MOD;
            k -= op;
        }

        return (int)ans;
    }
};