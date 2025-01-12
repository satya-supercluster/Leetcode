class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);

        // a -> b => b -> a
        int ans = 0;
        for (auto it : edges) {
            g[it[1]].push_back({it[0], it[2]});
            ans = max(ans, it[2]);
        }

        auto bfs = [&](int mid) -> bool {
            vector<int> vis(n, 0);

            queue<int> q;
            
            q.push(0);
            vis[0] = 1;

            int c = 1;

            while (!q.empty()) {
                auto u = q.front();
                q.pop();

                if (c == n) return true;

                for (auto v : g[u]) {
                    if (v.second <= mid and !vis[v.first]) {
                        vis[v.first] = 1;
                        c++;
                        q.push(v.first);
                    }
                }
            }

            return c == n;
        };
        
        if (!bfs(ans)) return -1;

        int lo = 0, hi = 1e6 + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (bfs(mid)) 
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        return ans;
    }
};