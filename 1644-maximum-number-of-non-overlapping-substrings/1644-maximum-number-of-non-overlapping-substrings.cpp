class Solution {
public:
    static bool comp(pair<int,int>& p1, pair<int,int>& p2)
    {
        return p1.first < p2.first;
    }

    int findJustGreater(vector<pair<int,int>>& intervals, int i, int j, int val)
    {
        if (i > j)
            return -1;

        int mid = i + (j-i)/2;

        if (intervals[mid].first < val)
            return findJustGreater(intervals, mid+1, j, val);
        else
        {
            int x = findJustGreater(intervals, i, mid-1, val);
            if (x != -1)
                return x;
            else
                return mid;
        }
    }

    int findMaximumNonOverlapIntervalSet(
        string& s, vector<pair<int,int>>& intervals, int i, vector<int>& dp, vector<vector<string>>& dpVal)
    {
        if (dp[i] != -1)
            return dp[i];

        string si = s.substr(intervals[i].first, intervals[i].second-intervals[i].first+1);

        if (i == intervals.size()-1)
        {
            dp[i] = 1;
            dpVal[i] = {si};
            return dp[i];
        }

        int pos1 = findMaximumNonOverlapIntervalSet(s, intervals, i+1, dp, dpVal);

        int j = findJustGreater(intervals, i+1, intervals.size()-1, intervals[i].second);
        if (j != -1)
        {
            int pos2 = 1 + findMaximumNonOverlapIntervalSet(s, intervals, j, dp, dpVal);
            if (pos1 == pos2)
            {
                dp[i] = pos1;

                int totLenPos1 = 0;
                for (int k = 0; k < dpVal[i+1].size(); k++)
                {
                    totLenPos1 += dpVal[i+1][k].length();
                }

                int totLenPos2 = si.length();
                for (int k = 0; k < dpVal[j].size(); k++)
                {
                    totLenPos2 += dpVal[j][k].length();
                }

                if (totLenPos1 < totLenPos2)
                {
                    dpVal[i] = dpVal[i+1];
                }
                else
                {
                    dpVal[i] = dpVal[j];
                    dpVal[i].push_back(si);
                }
            }
            else if (pos1 < pos2)
            {
                dp[i] = pos2;
                dpVal[i] = dpVal[j];
                dpVal[i].push_back(si);
            }
            else
            {
                dp[i] = pos1;
                dpVal[i] = dpVal[i+1];
            }
        }
        else
        {
            dp[i] = pos1;
            dpVal[i] = dpVal[i+1];
        }

        return dp[i];
    }

    void dfs(
        unordered_map<char, vector<int>>& rangeMap,
        unordered_map<char, unordered_set<char>>& charGraph,
        char c,
        int& left,
        int& right,
        unordered_set<char>& visited)
    {
        if (visited.find(c) != visited.end())
        {
            return;
        }

        visited.insert(c);

        left = min(left, rangeMap[c][0]);
        right = max(right, rangeMap[c][1]);

        for (auto childChar : charGraph[c])
        {
            dfs(rangeMap, charGraph, childChar, left, right, visited);
        }
    }

    vector<string> maxNumOfSubstrings(string s)
    {
        unordered_map<char, vector<int>> rangeMap;
        unordered_map<char, unordered_set<char>> charGraph;

        for (char c = 'a'; c <= 'z'; c++)
        {
            int i = 0;

            while (i < s.length() && s[i] != c)
                i++;

            if (i == s.length())
                continue;

            int first = i;
            i = s.length()-1;

            while (i >= first && s[i] != c)
                i--;

            int last = i;

            rangeMap[c] = {first, last};

            for (int i = first+1; i < last; i++)
            {
                charGraph[c].insert(s[i]);
            }
        }

        vector<pair<int,int>> intervals;
        unordered_set<string> uset;

        for (auto rc : rangeMap)
        {
            int left = INT_MAX, right = INT_MIN;
            unordered_set<char> visited;

            dfs(rangeMap, charGraph, rc.first, left, right, visited);

            if (uset.find(to_string(left) + "," + to_string(right)) == uset.end())
            {
                intervals.push_back({left, right});
                uset.insert(to_string(left) + "," + to_string(right));
            }
        }

        sort(intervals.begin(), intervals.end(), comp);
        vector<int> dp(intervals.size(), -1);
        vector<vector<string>> dpVal(intervals.size(), vector<string>(0, ""));

        findMaximumNonOverlapIntervalSet(s, intervals, 0, dp, dpVal);

        return dpVal[0];
    }
};