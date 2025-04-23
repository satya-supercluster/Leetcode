
class Solution {
public:
    int sumOfDigits(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    vector<int> ans = vector<int>(10001, 0);
    bool done = false;
    
    void precompute() {
        map<int,int> freq;
        int maxSize = 0;
        int numMax  = 0;
        for (int i = 1; i <= 10000; i++) {
            int s = sumOfDigits(i);
            int cnt = ++freq[s];
            if (cnt > maxSize) {
                maxSize = cnt;
                numMax  = 1;
            }
            else if (cnt == maxSize) {
                numMax++;
            }
            
            ans[i] = numMax;
        }
    }
    
    int countLargestGroup(int n) {
        if (!done) {
            precompute();
            done = true;
        }
        return ans[n];
    }
};
