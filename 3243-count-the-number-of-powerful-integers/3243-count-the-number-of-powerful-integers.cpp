class Solution {
public:

    long long adjustDown(long long m, int limit) {
        string s = to_string(m);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' > limit) {
                s[i] = char(limit + '0');
                for (int j = i + 1; j < s.size(); j++) {
                    s[j] = char(limit + '0');
                }
                break;
            }
        }
        return stoll(s);
    }
    
    long long constructCandidate(long long m, const string &suffixStr) {
        long long suffixVal = stoll(suffixStr);
        if (m == 0)
            return suffixVal;
        long long factor = 1;
        for (int i = 0; i < suffixStr.size(); i++)
            factor *= 10;
        return m * factor + suffixVal;
    }
    
    long long bSearch(long long start, long long finish, int limit, string s, bool upper) {
        long long factor = 1;
        for (int i = 0; i < s.size(); i++)
            factor *= 10;
        long long suffixVal = stoll(s);
        long long lo = 0;
        long long hi = finish / factor;
        long long ans = -1;
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long adjustedMid = adjustDown(mid, limit);
            long long candidate = (mid == 0 ? suffixVal : constructCandidate(adjustedMid, s));
            
            if (candidate < start) {
                lo = mid + 1;
            } else if (candidate > finish) {
                hi = mid - 1;
            } else {
                ans = adjustedMid;
                if (!upper)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return ans;
    }
    
    long long convertToBase(long long m, int limit) {
        string s = to_string(m);
        long long value = 0;
        int base = limit + 1;
        for (char c : s) {
            value = value * base + (c - '0');
        }
        return value;
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long smallest = bSearch(start, finish, limit, s, false);
        long long largest  = bSearch(start, finish, limit, s, true);
        if (smallest == -1)
            return 0;
        return convertToBase(largest, limit) - convertToBase(smallest, limit) + 1;
    }
};