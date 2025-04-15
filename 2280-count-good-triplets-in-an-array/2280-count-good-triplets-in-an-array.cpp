class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {  
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n), map(n);
        for(int i=0; i<n; i++){
            pos[nums2[i]] = i;
        }

        for(int i=0; i<n; i++){
            map[pos[nums1[i]]] = i;
        }

        FenwickTree tree(n);
        long long ans = 0;
        for(int i=0; i<n; i++){
            int pos = map[i];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n-1-pos)-(i-left);
            ans += (long long)left*right; 
        }
        return ans;
    }
};