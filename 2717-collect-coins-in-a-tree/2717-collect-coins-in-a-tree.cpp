class Solution {
public:
  int collectTheCoins(const vector<int>& coins, const vector<vector<int>>& edges) {
    int n = coins.size();
    vector<unordered_set<int>> g(n, unordered_set<int>());
    vector<int> degree(n, 0);
    for (auto& e : edges) {
      g[e.front()].insert(e.back());
      g[e.back()].insert(e.front());
      ++degree[e.back()];
      ++degree[e.front()];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1 && coins[i] == 0) {
        q.emplace(i);
      }
    }
    while (q.size()) {
      int i = q.front();
      q.pop();
      for (int n : g[i]) {
        if (--degree[n] == 1 && coins[n] == 0) {
          q.push(n);
        }
        g[n].erase(i);
      }
      g[i].clear();
      degree[i] = n;
    }
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        q.emplace(i);
      }
    }
    for (int t = 0; t < 2; ++t) {
      int len = q.size();
      while (len-- > 0) {
        int cur = q.front();
        q.pop();
        for (int next : g[cur]) {
          if (--degree[next] == 1) {
            q.push(next);
          }
          g[next].erase(cur);
        }
        g[cur].clear();
        degree[cur] = n;
      }
    }
    int left = 0;
    for (auto& v : g) {
      if (v.size() > 0) {
        ++left;
      }
    }
    return max(0, (left - 1) * 2);
  }
};