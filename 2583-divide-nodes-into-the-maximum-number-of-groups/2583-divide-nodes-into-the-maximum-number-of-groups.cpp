class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dis(n);
        for (int u = 0; u < n; ++u) {
            queue<int> q{{u}};
            vector<int> dist(n);
            dist[u] = 1;
            int mx = 1;
            int rn = u;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                rn = min(rn, curr);
                for (int child : adj[curr]) {
                    if (dist[child] == 0) {
                        dist[child] = dist[curr] + 1;
                        mx = max(mx, dist[child]);
                        q.push(child);
                    } else if (abs(dist[child] - dist[curr]) != 1) {
                        return -1;
                    }
                }
            }
            dis[rn] = max(dis[rn], mx);
        }
        return accumulate(dis.begin(), dis.end(), 0);
    }
};